#include <iostream>
#include <Windows.h>


int main()
{
    int first, second;
    std::cout << "Give two value to devide" << std::endl;
    std::cout << "first : ";
    std::cin >> first;
    std::cout << "second : ";
    
    std::cin >> second;
    
    if (second == 0)
        return -1;

    std::cout << "first / second = " << first / second << std::endl;
    getchar();
    return 0;
}