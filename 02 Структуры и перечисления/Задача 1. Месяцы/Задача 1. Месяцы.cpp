#include <iostream>

enum Months {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() {
    setlocale(LC_ALL, "Russian");
    int month = 1;
    while (month != 0) {
        std::cout << "Введите номер месяца (1-12): ";
        std::cin >> month;
        if (month == 0) {
            std::cout << "До свидания";
            break;
        }
        if (month >= 1 && month <= 12) {
            Months day = static_cast<Months>(month - 1);
            switch (day) {
            case January:
                std::cout << "Январь\n";
                break;
            case February:
                std::cout << "Февраль\n";
                break;
            case March:
                std::cout << "Март\n";
                break;
            case April:
                std::cout << "Апрель\n";
                break;
            case May:
                std::cout << "Май\n";
                break;
            case June:
                std::cout << "Июнь\n";
                break;
            case July:
                std::cout << "Июль\n";
                break;
            case August:
                std::cout << "Август\n";
                break;
            case September:
                std::cout << "Сентябрь\n";
                break;
            case October:
                std::cout << "Октябрь\n";
                break;
            case November:
                std::cout << "Ноябрь\n";
                break;
            case December:
                std::cout << "Декабрь\n";
                break;
            }
        }
        else {
            std::cout << "Неправильный номер!\n";
        }
    }

    return 0;
}
