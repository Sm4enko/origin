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
    first.city = "������";
    first.street = "�����";
    first.house = 12;
    first.apartment = 8;
    first.index = 123456;

    address second;
    second.city = "������";
    second.street = "�������";
    second.house = 59;
    second.apartment = 143;
    second.index = 953769;


    std::cout << std::endl << "�����: " << first.city << std::endl;
    std::cout << "�����: " << first.street << std::endl;
    std::cout << "����� ����: " << first.house << std::endl;
    std::cout << "����� ��������: " << first.apartment << std::endl;
    std::cout << "������: " << first.index << std::endl;

    std::cout << std::endl << "�����: " << second.city << std::endl;
    std::cout << "�����: " << second.street << std::endl;
    std::cout << "����� ����: " << second.house << std::endl;
    std::cout << "����� ��������: " << second.apartment << std::endl;
    std::cout << "������: " << second.index << std::endl;



    return 0;
}
