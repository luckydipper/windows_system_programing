#include <iostream>
#include <Windows.h> 
#include <tchar.h>

int main()
{

    HANDLE a = GetCurrentProcess();
    TCHAR command[] = _T("OperationStateChild.exe");

    STARTUPINFO start_info{ 0 };
    start_info.cb = sizeof(start_info);

    PROCESS_INFORMATION process_info{ 0 };

    bool is_run =CreateProcess(
        NULL, // ������ ���μ����� ���� ���� �̸�, ��� �߰����� ����
        command, // ���� command�� ����� ġ��, ������ process �̸�
        NULL, // p����
        NULL, // t����
        TRUE, // ��ӿ���
        CREATE_NEW_CONSOLE, //  CREATE_NEW_CONSOLE, Null processƯ�� ���ο� process���� ��.
        NULL, // ȯ�� ���� �� 
        NULL, // �����ϴ� ���μ����� ���� ���͸��� ���� 
        &start_info,
        &process_info
    );
    if (!is_run)
        return -1;

    //HANDLE operation1_handle = GetCurrentProcess();
    //SetPriorityClass(operation1_handle, HIGH_PRIORITY_CLASS);




    //block ���¿��� child process�� ���� �� ���� ��ٸ�
    WaitForSingleObject(process_info.hProcess, INFINITE); //3000

    //���������� ����ƴ��� �θ� child kernel object�� handle�� ������ Ȯ�ΰ���!
    DWORD process_exit_value;
    GetExitCodeProcess(process_info.hProcess, &process_exit_value);
    
    std::cout << "process exit value is " << process_exit_value << std::endl;


    //�ڽ� process�� ������ ����. program counter�� 1 ����
    CloseHandle(process_info.hProcess);
    CloseHandle(process_info.hThread);
}