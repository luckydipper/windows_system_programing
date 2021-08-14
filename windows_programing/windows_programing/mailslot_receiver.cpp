// Receiver

// Signaled : 꺼짐 
// None Signaled : 켜짐 
// Waitfor Single Object signaled 기다림
// get exit code

#include <iostream>
#include <Windows.h>
#include <tchar.h>

int main()
{
    // Create mail slot.
    HANDLE receive_mail_handle =
        CreateMailslot(
        _T("//./mailslot/mailbox"),// mail slot의 이름 \\computername\mailslot\[path]name /computername과 path name부분만 수정하면 됨.
        0,// maile buffer 크기. 0일경우 최대로
        MAILSLOT_WAIT_FOREVER,// mail slot의 데이터가 채워지기 까지 기다리는 시간 
        NULL // 핸들을 상속하기 위한 용도 
    );

    // Check Validation
    if (receive_mail_handle == INVALID_HANDLE_VALUE)
    {
        std::cout << "error";
        return 1;
    }

    // Message receiving
    while (true)
    {
        TCHAR message_box[50] = { 0 };
        DWORD bytes_read;

        //   (mail_box_handle, 읽어들일 데이터 저장, 읽어들일 최대 크기, 함수 호출 수 읽어들인 데이터 크기, 비동기 overlapped)
        if (!ReadFile(receive_mail_handle, message_box, sizeof(CHAR) * 50/*sizeof(message_box)*/, &bytes_read, NULL))
        {
            std::cout << "unable to read";
            CloseHandle(receive_mail_handle);
            return -1;
        }
        

        //
        if ( !_tcsncmp(message_box, _T("exit"), 4) )
        {
            std::cout << "exit program";
            break;
        }

        message_box[bytes_read / sizeof(TCHAR)] = 0;
        _fputts(message_box, stdout);
        std::cout << std::endl;
    }

    CloseHandle(receive_mail_handle);
    return 0;
}