#include <iostream>

int function(std::string str, int forbidden_length) {
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    while (str.size() != forbidden_length) {
        std::cout << "Введите слово: ";
        std::cin >> str;
        try {
            if (str.size() == forbidden_length) {
                throw "Вы ввели слово запретной длины! До свидания";
            }
            std::cout << "Длинна слова " << '"' << str << " равна " << str.size() << std::endl;
        }
        catch (const char* exception) {
            std::cout << exception << std::endl;
        }
    }
    return forbidden_length;
}


int main() {
    setlocale(LC_ALL, "Russian");


    std::string str;
    int forbidden_length = 0;

    function(str, forbidden_length);


    return 0;
}


