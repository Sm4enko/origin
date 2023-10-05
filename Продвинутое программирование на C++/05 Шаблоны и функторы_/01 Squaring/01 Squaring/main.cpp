#include <iostream>
#include <vector>
#include <string>

template <class T>
T squaring(T a)
{
    int b = a * a;
    a *= a;
    std::cout << "[OUT] : " << b << std::endl;
 return b;
}

template<typename T>
std::vector<T> squaring(const std::vector<T> nums) {
    
    std::vector<int> b;
    for (size_t i = 0; i < nums.size(); ++i) {
        b.push_back(nums[i] * nums[i]);
    }
    std::cout << "[OUT] : ";
    for (int i : b) {
        std::cout << i << ' ';
    }
    
    return b;
}

int main(int argc, const char * argv[]) {
    int num;
    std::string line, temp;
    std::vector<int> nums;
    
    std::cout << "[IN] : ";
    std::cin >> num;
    squaring(num);
    std::cin.ignore();
    
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
    squaring(nums);
}


