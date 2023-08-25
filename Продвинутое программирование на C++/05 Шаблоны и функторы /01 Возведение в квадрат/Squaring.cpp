#include <iostream>
#include <vector>
#include <string>

template <class T>
T squaring(T a)
{
    a *= a;
 return a;
}

template<typename T>
std::vector<T> squaring(std::vector<T>& nums) {
   
    for (size_t i = 0; i < nums.size(); ++i) {
        nums[i] = nums[i] * nums[i];
    }
    return nums;
}

int main(int argc, const char * argv[]) {
    int num;
    std::string line, temp;
    std::vector<int> nums;
    
    std::cout << "[IN] : ";
    std::cin >> num;
    std::cout << "[OUT] : " << squaring(num) << std::endl;
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
    std::cout << "[OUT] : ";
    for (int i : nums) {
        std::cout << i << ' ';
    }
}



