#include <iostream>

#include <vector>

#include <algorithm>



int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };



    std::cout << "������� ������: ";

    auto display = [](int& num) {
        std::cout << num << ' ';

    };



    std::for_each(numbers.begin(), numbers.end(), display);

    std::cout << std::endl;





    auto multiplyByThreeIfOdd = [](int& num) {
        if (num % 2 != 0) {
            num *= 3;

        }



    };



    std::for_each(numbers.begin(), numbers.end(), multiplyByThreeIfOdd);



    std::cout << "�������� ����� ���������: ";

    for (int num : numbers) {
        std::cout << num << " ";

    }

    std::cout << std::endl;



    return 0;

}

