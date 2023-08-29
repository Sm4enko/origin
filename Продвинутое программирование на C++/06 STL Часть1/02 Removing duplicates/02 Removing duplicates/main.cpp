#include <iostream>
#include <set>
#include <vector>
#include <list>

int main(int argc, const char * argv[]) {
    std::set<int> sortNumbers;
    int num = 0;
    std::vector<int> numbers;
    std::list<int> reverse;
    std::cout << "[IN] : \n";
    std::cout << 6 << std::endl;
    
    for (int i = 0; i < 6; ++i) {
        std::cin >> num;
        numbers.push_back(num);
        std::cin.ignore();
    }
    
    for (auto i : numbers) {
        sortNumbers.insert(i);
    }
    
    for (auto I : sortNumbers) {
        reverse.push_front(I);
    }
    
    std::cout << "[OUT]:\n";
    for (auto I : reverse) {
        std::cout << I << std::endl;
    }
    
    return 0;
}


