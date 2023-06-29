#include "Name.h"
#include <iostream>

std::string WordStorage::storedWord = "";

void WordStorage::setWord(const std::string& word) {
    storedWord = word;
}

void WordStorage::printWord() {
    std::cout << "Здравствуйте: " << storedWord << std::endl;
}
