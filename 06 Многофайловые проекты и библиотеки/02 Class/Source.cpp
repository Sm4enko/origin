#include <iostream>
#include <string>
#include "windows.h"

class Counter {
private:
    int num;

public:
    Counter(int n) {
        num = n;
    }
    int add() {
        num += 1;
        return num;
    }
    int subtract() {
        num -= 1;
        return num;
    }
    int getValue() {
        return num;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int number = 1;
    char sym;
    std::string answer;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    getline(std::cin, answer);
    if (answer == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> number;
    }
    Counter count(number);
    while (1 != 2) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'):\n";
        std::cin >> sym;


        if (sym == '+') {
            count.add();
        }
        else if (sym == '-') {
            count.subtract();
        }
        else if (sym == '=') {
            std::cout << count.getValue() << std::endl;
        }
        else if (sym == 'x') {
            std::cout << "До свидания!";
            break;
        }


    }

    return 0;
}
