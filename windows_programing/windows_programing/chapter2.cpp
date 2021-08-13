//문자열 다루기
//WBCS(wide), MBCS(multi), SBCS(single), byte character set
//ANSI 표준

//ASCII vs UNICODE는 다른 이야기일 가능성이 큽니다. blog posting 참고.

#include <cstdio>
#include <iostream>
#include <string>


// wide character 를 쓰면, 문자열의 size 가 일정해진다. 
//void UseWideChar()
//{
//
//}


int wmain(int argc, wchar_t* argv[])
{
    //char str[] = "En한글";
    //wchar_t wide_character[] = L"En한글";
    //int size = sizeof(str);
    //int len = strlen(str);

    //printf("배열 크기 %d \n", size); // 7 /0공간 포함
    //printf("문자열 길이 %d\n", len); // 6 = 1+1+2+2
    //_wsetlocale(LC_ALL, L"korean");
    //wprintf(wide_character);

    //std::string stl_string{ str };
    //std::cout << sizeof(wide_character) <<"\n" << sizeof(str); //10 = 2+2+2+2+2 , 7 = 1+1+2+2+1
    //std::cout << stl_string.size() << std::endl;
    //std::cout << stl_string.length() << std::endl;
    for (int i = 0; i < argc; i++)
        fputws(argv[i], stdout);
    return 0;  
}