
#include <iostream>
#include "windows.h"
#include "../N/Name.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string name;
    std::cout << "¬ведите им€: ";
    std::cin >> name;
    WordStorage::setWord(name);
    WordStorage::printWord();


    return 0;
}
