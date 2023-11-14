#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

template <typename Iterator, typename Function>
void parallel(Iterator begin, Iterator end, Function func, size_t range) {
    const size_t size = std::distance(begin, end);

    if (size <= range) {
        std::for_each(begin, end, func);
    } else {
      
        Iterator middle = begin + size / 2;

        auto future_first_half = std::async(std::launch::async, parallel<Iterator, Function>, begin, middle, func, range);

        parallel(middle, end, func, range);

        future_first_half.wait();
    }
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    auto square = [](int &num) { num *= num; };

    size_t range = 2;

    parallel(numbers.begin(), numbers.end(), square, range);

    for (const auto &num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
