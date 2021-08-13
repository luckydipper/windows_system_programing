#include <iostream>
#include <Windows.h>
#include <regex>
#include <stdbool.h>
#include "CreateProcessPractice.h"
using namespace std;


bool FlagProcessing(const int argc, const char* argv[])
{
    const char* last_flag{ argv[argc -1] };

    //Last flag is run
    if (!strcmp(last_flag, "run"))
        return true;
    else
    {
        ShowUsage();
        return false;
    }
}

void ShowUsage()
{
    cout << "This Module Create Process" << endl;
    cout << "If you want to run, add flag run" << endl;
}
