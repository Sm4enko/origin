#include <iostream>
#include <vector>
#include <string>

class MyFunctor {

public:
    MyFunctor(int num) : number(num) {}
    int get_sum(int obj) {
        if(obj == obj / 3 * 3) {
            number += obj;
        }
            return number;
    }
    
    int zero() {
        number = 0;
        return number;
    }
    
    int get_count(int obj) {
        if(obj == obj / 3 * 3) {
            ++number;
        }
            return number;
    }
private:
    int number;
};


int main() {
    int result = 0;
    std::string line, temp;
    std::vector<int> nums;
    std::cout << "[IN] : ";
    std::getline(std::cin, line);
   
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] != ' ') {
            temp += line[i];
        }
        else if (line[i] == ' ') {
            nums.push_back(std::stoi(temp));
            temp = "";
        }
    }
    nums.push_back(std::stoi(temp));
    MyFunctor myFunctor(result);
    for (int i = 0; i < nums.size(); ++i) {
        result = myFunctor.get_sum(nums[i]);
    }
    std::cout << "[OUT]: get_sum() = " << result << std::endl;
    myFunctor.zero();
    for (int i = 0; i < nums.size(); ++i) {
        result = myFunctor.get_count(nums[i]);
    }
    std::cout << "[OUT]: get_count() = " << result << std::endl;
    
    return 0;
}


