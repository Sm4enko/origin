#include <iostream>
#include <set>
#include <vector>
#include <list>

template <typename Container>
void print_container(const Container& container) {
    for (const auto& I : container) {
        std::cout << I << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> vectorData = {"one", "two", "three", "four"};
    std::list<std::string> listData = {"one", "two", "three", "four"};
    std::set<std::string> setData = {"one", "two", "three", "four"};

    std::cout << "Set contents: ";
    print_container(setData);
    
    std::cout << "List contents: ";
    print_container(listData);
    
    std::cout << "Vector contents: ";
    print_container(vectorData);

    return 0;
}
