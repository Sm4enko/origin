
#include <iostream>
#include "windows.h"
#include "../03 Cmake динамическая библиотека/Name.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    WordStorage::setWord(name);
    WordStorage::printWord();


    return 0;
}
