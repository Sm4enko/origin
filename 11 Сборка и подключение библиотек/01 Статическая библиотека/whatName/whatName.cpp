
#include <iostream>
#include "../staticLibrary/Name.h"
#include "windows.h"

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

 


