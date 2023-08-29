#include <iostream>
#include <string>
#include <list>
#include <map>

int main(int argc, const char * argv[]) {
    std::string line, line2;
    std::list<char> letters;
    std::list<int> numbers;
    std::map<char, int> dictionary;
    int count = 0;
    int temp;

    
    std::cout << "[IN] : ";
    std::getline(std::cin, line);
    
    for (int i = 0; i < line.size(); ++i) {
        for (int j = 0; j < line.size(); ++j) {
            if (line[i] == line[j]) {
                ++count;
            }
        }
        dictionary.insert(std::make_pair(line[i], count));
        count = 0;
    }
    
    count = 0;
    for (auto k : dictionary) {
        ++count;
    }
    temp = count;
    
    while(letters.size() != dictionary.size()) {
        for (auto I : dictionary) {
            if (I.second == count) {
                letters.push_front(I.first);
                numbers.push_front(I.second);
            }
        }
        --count;
    }
    
    line = "";
    for (auto I : letters) {
        line += I;
    }
    for (auto I : numbers) {
        line2 += std::to_string(I);
    }
    std::cout << "[OUT] : \n";
    
    for (int i = temp; i > 0; --i) {
        std::cout << line[i] << ' ' << line2[i] << std::endl;
    }
    
    return 0;
}


