// adder process�� �־�� ���� ������.

#include "CreateProcessPractice.h"
#include <iostream>
#include <Windows.h>
#include <tchar.h>
using namespace std;


// If flag is valid, run process.
//if (bool is_running = FlagProcessing(argc, argv))
//    cout << "---- program start ----" << endl;
//else
//    return -1;
void ShowDirectoryChange()
{
    TCHAR current_directory[MAX_PATH + 1] = _T("");
    GetCurrentDirectory(MAX_PATH + 1, current_directory);
    _fputts(current_directory, stdout);
    _fputts(_T("\n"), stdout);

    SetCurrentDirectory(_T("C:\\WinSystem"));
    GetCurrentDirectory(MAX_PATH + 1, current_directory);
    _fputts(current_directory, stdout);
    _fputts(_T("\n"), stdout);

    GetSystemDirectory(current_directory, MAX_PATH + 1);
    _fputts(current_directory, stdout);
    _fputts(_T("\n"), stdout);

    GetWindowsDirectory(current_directory, MAX_PATH + 1);
    _fputts(current_directory, stdout);
    _fputts(_T("\n"), stdout);
}


int main(const int argc, const char* argv[])
{
    ShowDirectoryChange();

    //set startup infomation
    STARTUPINFO start_info = { 0 };
    start_info.cb = sizeof(start_info);
    start_info.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
    start_info.dwX = 100;
    start_info.dwY = 200;
    start_info.dwXSize = 300;
    start_info.dwYSize = 200;
    start_info.lpTitle = (LPWSTR)_T("Should be? T?");
    
    TCHAR command[] = _T("AdderProcess.exe 6666 111");
    TCHAR exectue_notepad[] = _T("notepad.exe");
    PROCESS_INFORMATION process_info = { 0 };

    bool is_created = CreateProcess(
        NULL, // execution file name
        command,//exectue_notepad, // process�� argc argv parameter�� ���� ù��° param�� null�� ���, ���⿡ �������� �̸��� ����. ���ϱ� ������ ����, Lvalue ���� �־����,
        NULL, // ����� handle talble �� ����
        NULL, // thread ����
        TRUE, // handle table�� ������� ����
        CREATE_NEW_CONSOLE, // ���μ����� Ư��(priority ����)�� �������� �� ����ϴ� �ɼ�. //������ �θ�� �ܼ��� �����Ѵ�.
        NULL, // environmnet block ���� (environment block), null�̸� �θ� process ȯ�溯�� ������.
        NULL, // �ڽ� process�� directory�����Ѵ�. null�̸� �θ�� ����.
        &start_info, // �����ϴ� ���μ����� �Ӽ�
        &process_info // �����ϴ� ���μ����� ������ �����Ѵ�.
        );

    //�̰ɷ� game window�� size�� �÷ȴ� �ٿ��� �ϴ� ��.
    //SetProcessInformation();

    CloseHandle(process_info.hProcess);
    CloseHandle(process_info.hThread);


    if (!is_created)
        cout << "There is no execution file";
        return -1;



    //CreateProcess();
}
