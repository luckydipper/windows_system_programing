// Signaled : 꺼짐 
// None Signaled : 켜짐 
// Waitfor Single Object signaled 기다림
// get exit code


#include <iostream>
#include <Windows.h>
#include <tchar.h>

int main()
{
    HANDLE message_handle =
        CreateFile(
            _T("//./mailslot/mailbox"),         // mailslot 이름, 파일 이름
            GENERIC_WRITE,                      // 사용 용도, 읽기 쓰기 or 연산으로 묶어서 보낼 수 있음.
            FILE_SHARE_READ,                    // share mode 공유 방식. 다른 프로세스에서 동시 접근 가능. 0이면 공유 불가. file write이면 같은영역 쓰면 안됨
            NULL,                               // 보안속성 핸들을 상속할지 결정 Security Attribute
            OPEN_EXISTING,                      // 파일의 특성 정보를 설정. 
            FILE_ATTRIBUTE_NORMAL,              // 
            NULL);                              // 파일과 동일한 특성가지는 새 파일을 만들 때 사용
    
    //mailslot validation check
    if (message_handle == INVALID_HANDLE_VALUE)
    {
        std::cout << "unable to create mailslot";
        return 1;
    }

    // sending mail
    TCHAR message[50];
    DWORD bytesWritten; //number of byte write
    while(true)
    {
        //write input
        _fputts(_T("Write message to send"), stdout);
        _fgetts(message, sizeof(message) / sizeof(TCHAR), stdin);

        //check validation
        if (!WriteFile(message_handle, message, _tcslen(message) * sizeof(TCHAR), &bytesWritten, NULL))
        {
            std::cout << "Unable to write";
            return 1;
        }

        //check Exit code
        if (!_tcscmp(message, _T("exit")))
        {
            std::cout << "Exit program";
            return 0;
        }

    }
    CloseHandle(message_handle);
    return 0;
}