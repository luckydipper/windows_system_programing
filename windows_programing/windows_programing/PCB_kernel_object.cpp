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
        NULL, // 생성할 프로세스의 실행 파일 이름, 경로 추가지정 가능
        command, // 원래 command를 여기다 치고, 위에는 process 이름
        NULL, // p보안
        NULL, // t보안
        TRUE, // 상속여부
        CREATE_NEW_CONSOLE, //  CREATE_NEW_CONSOLE, Null process특성 새로운 process만들 때.
        NULL, // 환경 변수 블럭 
        NULL, // 생성하는 프로세스의 현재 디렉터리를 설정 
        &start_info,
        &process_info
    );
    if (!is_run)
        return -1;

    //HANDLE operation1_handle = GetCurrentProcess();
    //SetPriorityClass(operation1_handle, HIGH_PRIORITY_CLASS);




    //block 상태에서 child process가 끝날 때 까지 기다림
    WaitForSingleObject(process_info.hProcess, INFINITE); //3000

    //정상적으로 종료됐는지 부모가 child kernel object의 handle을 가지고 확인가능!
    DWORD process_exit_value;
    GetExitCodeProcess(process_info.hProcess, &process_exit_value);
    
    std::cout << "process exit value is " << process_exit_value << std::endl;


    //자식 process와 연결을 끊음. program counter를 1 낮춤
    CloseHandle(process_info.hProcess);
    CloseHandle(process_info.hThread);
}