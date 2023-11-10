#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <iomanip>

std::mutex mtx;
std::atomic<int> progress1(0);
std::atomic<int> progress2(0);

void updateProgressBar(std::atomic<int>& progress, int total) {
    while (progress < total) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        {
            std::unique_lock<std::mutex> lock(mtx);
            progress++;
        }
    }
}

void printProgressBar(std::atomic<int>& progress, int total, int line, std::mutex& mtx) {
    while (progress < total) {
        int barWidth = 50;
        int pos = (progress * barWidth) / total;

        std::string progressBar = "Progress " + std::to_string(line) + ": [";
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) {
                progressBar += "#";
            }
            else {
                progressBar += "-";
            }
        }

        progressBar += "] " + std::to_string((progress * 100) / total) + "%";

        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "\033[" << line << ";0H";
        std::cout << progressBar << std::flush;
    }
}

int main() {
    int total = 50;

    std::thread thread1(updateProgressBar, std::ref(progress1), total);
    std::thread thread2(updateProgressBar, std::ref(progress2), total);

    std::thread printThread1(printProgressBar, std::ref(progress1), total, 1, std::ref(mtx));
    std::thread printThread2(printProgressBar, std::ref(progress2), total, 2, std::ref(mtx));

    thread1.join();
    thread2.join();
    printThread1.join();
    printThread2.join();

    std::cout << "\033[3;0H";

    return 0;
}
