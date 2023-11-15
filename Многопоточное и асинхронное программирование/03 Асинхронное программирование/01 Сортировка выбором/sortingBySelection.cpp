#include <iostream>
#include <vector>
#include <future>
#include <algorithm>
#include <thread>

std::future<int> findMin(const std::vector<int>& vec, size_t start, size_t end) {
    return std::async([=] {
        return static_cast<int>(std::min_element(vec.begin() + start, vec.begin() + end) - vec.begin());
        });
}

void sorting(std::vector<int>& vec) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        auto minFuture = findMin(vec, i, vec.size());
        int minIndex = minFuture.get(); 

        std::swap(vec[i], vec[minIndex]);
    }
}

int main() {
    std::vector<int> numbers = { 2, 37, 18, 24, 100, 300 };

    sorting(numbers);

    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
