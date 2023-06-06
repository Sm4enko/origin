#include <iostream>

int function(std::string str, int forbidden_length) {
    std::cout << "������� ��������� �����: ";
    std::cin >> forbidden_length;

    while (str.size() != forbidden_length) {
        std::cout << "������� �����: ";
        std::cin >> str;
        try {
            if (str.size() == forbidden_length) {
                throw "�� ����� ����� ��������� �����! �� ��������";
            }
            std::cout << "������ ����� " << '"' << str << " ����� " << str.size() << std::endl;
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


