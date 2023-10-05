#include <iostream>
#include <vector>
#include <string>

class MyFunctor {
public:
int sum;
int count;

MyFunctor() : sum(0), count(0) {}

     void operator()(int num) {
         if (num % 3 == 0) {
            sum += num;
            ++count;
         }
     }

     int get_count() const {
         return count;
     }

     int get_sum() const {
         return sum;
     }

     void zero() {
         sum = 0;
         count = 0;
     }
};

int main() {
    int result = 0;
    std::string str, temp;
    std::vector<int> nums;
    std::cout << "[IN] : ";
    std::getline(std::cin, str);

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != ' ') {
            temp += str[i];
        } else if (str[i] == ' ') {
            nums.push_back(std::stoi(temp));
            temp = "";
        }
    }
    nums.push_back(std::stoi(temp));

    MyFunctor myFunctor;
    for (int i = 0; i < nums.size(); ++i) {
        myFunctor(nums[i]);
    }

    std::cout << "[OUT]: get_sum() = " << myFunctor.get_sum() << std::endl;
    myFunctor.zero();
    
    for (int i = 0; i < nums.size(); ++i) {
        myFunctor(nums[i]);
    }
    
    std::cout << "[OUT]: get_count() = " << myFunctor.get_count() << std::endl;

    return 0;
}

