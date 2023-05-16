#include <iostream>
#include <string>
#include "windows.h"

struct address {
    std::string city;
    std::string street;
    int house;
    int apartment;
    int index;
};


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    address first;
    first.city = "Москва";
    first.street = "Арбат";
    first.house = 12;
    first.apartment = 8;
    first.index = 123456;

    address second;
    second.city = "Ижевск";
    second.street = "Пушкина";
    second.house = 59;
    second.apartment = 143;
    second.index = 953769;


    std::cout << std::endl << "Город: " << first.city << std::endl;
    std::cout << "Улица: " << first.street << std::endl;
    std::cout << "Номер дома: " << first.house << std::endl;
    std::cout << "Номер квартиры: " << first.apartment << std::endl;
    std::cout << "Индекс: " << first.index << std::endl;

    std::cout << std::endl << "Город: " << second.city << std::endl;
    std::cout << "Улица: " << second.street << std::endl;
    std::cout << "Номер дома: " << second.house << std::endl;
    std::cout << "Номер квартиры: " << second.apartment << std::endl;
    std::cout << "Индекс: " << second.index << std::endl;



    return 0;
}
