#include <iostream>
#include <vector>
#include <future>
#include <algorithm>

void sorting(std::vector<int>& vec, std::promise<std::vector<int>> promise) {

    for (int i = 0; i < vec.size() - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(vec[i], vec[minIndex]);
    }

    promise.set_value(vec);
}

int main() {
 
    std::vector<int> numbers = { 2, 15, 1, 33, 42 };

    std::promise<std::vector<int>> promise;
    std::future<std::vector<int>> future = promise.get_future();

    std::thread sortingThread(sorting, std::ref(numbers), std::move(promise));

    std::vector<int> toSort = future.get();

    std::cout << "Sorted numbers: ";
    for (int num : toSort) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sortingThread.join();

    return 0;
}
