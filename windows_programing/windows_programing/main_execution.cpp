// adder process가 있어야 실행 가능함.

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
        command,//exectue_notepad, // process에 argc argv parameter를 보냄 첫번째 param이 null일 경우, 여기에 실행파일 이름을 넣음. 변하기 때문에 변수, Lvalue 값을 넣어야해,
        NULL, // 상속할 handle talble 및 보안
        NULL, // thread 보안
        TRUE, // handle table을 상속할지 말지
        CREATE_NEW_CONSOLE, // 프로세스의 특성(priority 같은)을 경정지을 때 사용하는 옵션. //없으면 부모와 콘솔을 공유한다.
        NULL, // environmnet block 관리 (environment block), null이면 부모 process 환경변수 복사함.
        NULL, // 자식 process의 directory설정한다. null이면 부모랑 같다.
        &start_info, // 생성하는 프로세스의 속성
        &process_info // 생성하는 프로세스의 정보를 전달한다.
        );

    //이걸로 game window의 size를 늘렸다 줄였다 하는 듯.
    //SetProcessInformation();

    CloseHandle(process_info.hProcess);
    CloseHandle(process_info.hThread);


    if (!is_created)
        cout << "There is no execution file";
        return -1;



    //CreateProcess();
}
