#include <iostream>
#include <Windows.h>
#include <tchar.h>

int main()
{
    HANDLE message_handle =
        CreateFile(
            _T("//./mailslot/mailbox"),         // mailslot 이름
            GENERIC_WRITE,                      // 사용 용도
            FILE_SHARE_READ,
            NULL,
            OPEN_EXISTING,                      // 생성ㅇ 방식
            FILE_ATTRIBUTE_NORMAL,
            NULL);
    
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