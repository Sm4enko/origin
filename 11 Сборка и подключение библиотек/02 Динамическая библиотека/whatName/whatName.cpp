
#include <iostream>
#include "windows.h"
#include "../dynamicLibrary/Name.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string name;
    std::cout << "������� ���: ";
    std::cin >> name;
    WordStorage::setWord(name);
    WordStorage::printWord();


    return 0;
}
