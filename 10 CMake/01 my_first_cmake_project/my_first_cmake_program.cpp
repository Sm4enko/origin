#include <iostream>
#include <string>
#include "windows.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string name;

    std::cout << "Введите имя: ";

    std::cin >> name;

    std::cout << "Здравствуйте, " << name;
     
    return 0;
}
