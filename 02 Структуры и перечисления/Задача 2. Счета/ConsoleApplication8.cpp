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
    std::cout << std::endl << "������� ����� �����: ";
    std::cin >> number;
    std::cout << "������� ��� ���������: ";
    std::cin >> name;
    std::cout << "������� ������: ";
    std::cin >> money;
    std::cout << "������� ����� ������: ";
    std::cin >> money;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bankAccount client;
    client.number = 20;
    client.name = "����";
    client.money = 10000.5;



    cout << "������:" << endl;
    cout << "����� �����: " << client.number << endl;
    cout << "���: " << client.name << endl;
    cout << "������: " << client.money << endl;

    cout << endl;

    balance(client.number, client.name, client.money);
    cout << "������ 1:" << endl;
    cout << "����� �����: " << client.number << endl;
    cout << "���: " << client.name << endl;
    cout << "������: " << client.money << endl;

    return 0;
}
