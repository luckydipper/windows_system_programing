//���ڿ� �ٷ��
//WBCS(wide), MBCS(multi), SBCS(single), byte character set
//ANSI ǥ��

//ASCII vs UNICODE�� �ٸ� �̾߱��� ���ɼ��� Ů�ϴ�. blog posting ����.

#include <cstdio>
#include <iostream>
#include <string>


// wide character �� ����, ���ڿ��� size �� ����������. 
//void UseWideChar()
//{
//
//}


int wmain(int argc, wchar_t* argv[])
{
    //char str[] = "En�ѱ�";
    //wchar_t wide_character[] = L"En�ѱ�";
    //int size = sizeof(str);
    //int len = strlen(str);

    //printf("�迭 ũ�� %d \n", size); // 7 /0���� ����
    //printf("���ڿ� ���� %d\n", len); // 6 = 1+1+2+2
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