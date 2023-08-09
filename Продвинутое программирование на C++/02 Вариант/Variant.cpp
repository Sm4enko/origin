#include <iostream>

#include <variant>

#include <vector>





std::variant<int, std::string, std::vector<int>> get_variant() {

    std::srand(std::time(nullptr));

    int random_variable = std::rand() % 3;



    std::variant<int, std::string, std::vector<int>> result;

    switch (random_variable)

    {
    case 0:

        result = 5;

        break;

    case 1:

        result = "string";

        break;

    case 2:

        result = std::vector<int>{ 1, 2, 3, 4, 5 };

        break;

    default:

        break;

    }



    if (std::holds_alternative<std::vector<int>>(result)) {
        std::vector<int> intVector = std::get<std::vector<int>>(result);

        for (const int& num : intVector) {
            std::cout << num << " ";

        }

        std::cout << std::endl;

    }
    else if (std::holds_alternative<std::string>(result)) {
        std::cout << std::get<std::string>(result);

    }

    else if (std::holds_alternative<int>(result)) {
        int value = std::get<int>(result);

        value *= 2;

        result = value;

        std::cout << std::get<int>(result);

    }

    return result;

}





int main() {
    get_variant();



    return 0;

}

