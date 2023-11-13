#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#include <iomanip>
#include <string>
#include <chrono>

std::mutex mtx;
std::vector<std::shared_ptr<std::atomic<int>>> progresses;

void updateProgressBar(std::shared_ptr<std::atomic<int>> progress, int total) {
    while (*progress < total) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        {
            std::unique_lock<std::mutex> lock(mtx);
            (*progress)++;
        }
    }
}

void drawRowProgress(std::shared_ptr<std::atomic<int>> progress, int total, int line, std::mutex& mtx) {
    auto start_time = std::chrono::steady_clock::now();
    while (*progress < total) {
        
        
        int barWidth = 50;
        int pos = (*progress * barWidth) / total;

        std::string progressBar = "Progress " + std::to_string(line) + ": ";
        for (int i = 0; i < barWidth; ++i) {
            for (int k = 0; k < 1000000; ++k) {

            }
            if (i < pos) {
                progressBar += "#";
            }
            else {
                progressBar += ' ';
            }
        }

        progressBar += " ";

        std::unique_lock<std::mutex> lock(mtx);
        
        std::cout << "\033[" << line << ";0H";
        std::cout << std::this_thread::get_id() << ' ' << progressBar << std::flush;
    }
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << elapsed_time.count() << "ms";
   
}

int main() {
    setlocale(LC_ALL, "Russian");
    int total = 50;
    int numThreads;

    std::cout << "Введите количество потоков: ";
    std::cin >> numThreads;

    progresses.resize(numThreads);

    std::vector<std::thread> threads;
    std::vector<std::thread> printThreads;

    for (int i = 0; i < numThreads; ++i) {
        progresses[i] = std::make_shared<std::atomic<int>>(0);
        threads.emplace_back(updateProgressBar, progresses[i], total);
        printThreads.emplace_back(drawRowProgress, progresses[i], total, i + 1, std::ref(mtx));
    }

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
        printThreads[i].join();
    }

    std::cout << "\033[" << numThreads + 1 << ";0H";

    return 0;
}
