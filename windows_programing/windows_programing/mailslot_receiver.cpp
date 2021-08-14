// Receiver

// Signaled : ���� 
// None Signaled : ���� 
// Waitfor Single Object signaled ��ٸ�
// get exit code

#include <iostream>
#include <Windows.h>
#include <tchar.h>

int main()
{
    // Create mail slot.
    HANDLE receive_mail_handle =
        CreateMailslot(
        _T("//./mailslot/mailbox"),// mail slot�� �̸� \\computername\mailslot\[path]name /computername�� path name�κи� �����ϸ� ��.
        0,// maile buffer ũ��. 0�ϰ�� �ִ��
        MAILSLOT_WAIT_FOREVER,// mail slot�� �����Ͱ� ä������ ���� ��ٸ��� �ð� 
        NULL // �ڵ��� ����ϱ� ���� �뵵 
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

        //   (mail_box_handle, �о���� ������ ����, �о���� �ִ� ũ��, �Լ� ȣ�� �� �о���� ������ ũ��, �񵿱� overlapped)
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