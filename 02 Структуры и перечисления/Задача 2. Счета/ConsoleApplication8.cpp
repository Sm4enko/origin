#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct bankAccount {
    int number;
    string name;
    double money;
};

void balance(int& number, string& name, double& money) {
    std::cout << std::endl << "Введите номер счёта: ";
    std::cin >> number;
    std::cout << "Введите имя владельца: ";
    std::cin >> name;
    std::cout << "Введите баланс: ";
    std::cin >> money;
    std::cout << "Введите новый баланс: ";
    std::cin >> money;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bankAccount client;
    client.number = 20;
    client.name = "Иван";
    client.money = 10000.5;



    cout << "Клиент:" << endl;
    cout << "Номер счета: " << client.number << endl;
    cout << "Имя: " << client.name << endl;
    cout << "Деньги: " << client.money << endl;

    cout << endl;

    balance(client.number, client.name, client.money);
    cout << "Клиент 1:" << endl;
    cout << "Номер счета: " << client.number << endl;
    cout << "Имя: " << client.name << endl;
    cout << "Деньги: " << client.money << endl;

    return 0;
}
