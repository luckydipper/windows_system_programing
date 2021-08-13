#include <iostream>
#include <tchar.h>
#include <windows.h>




int _tmain(int argc, char* argv[])
{
    std::cout << "Process started" << std::endl;
    DWORD val1, val2;
    if (argc == 1)
    {
        std::cout << "error";
        return -1;
    }
    val1 = atoi(argv[1]);
    val2 = atoi(argv[2]);

    std::cout << val1 << '+' << val2 << '=' << val1+val2;
    _gettchar();

    return 0;
}
