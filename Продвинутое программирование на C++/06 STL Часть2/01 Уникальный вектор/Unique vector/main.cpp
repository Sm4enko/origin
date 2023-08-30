#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main() {
    
    std::string str, temp;
    std::vector<int> numbers;
    std::set<int> numbers2;
    
    std::cout << "[IN] : ";
    std::getline(std::cin, str);
    
    for (int i = 0; i < str.size(); ++i) {
        temp += str[i];
        if (str[i] == ' ') {
            numbers.push_back(stoi(temp));
            temp = "";
        }
    }
    numbers.push_back(stoi(temp));
    
    for (auto I : numbers) {
        numbers2.insert(I);
    }
    
    numbers.clear();
    
    for (auto I : numbers2) {
        numbers.push_back(I);
    }

    std::sort(numbers.begin(), numbers.end());

    auto last = std::unique(numbers.begin(), numbers.end());
    numbers.erase(last, numbers.end());
    
    std::cout << "[OUT] : ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}

