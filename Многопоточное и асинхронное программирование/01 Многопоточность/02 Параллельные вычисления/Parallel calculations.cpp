#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <string>

void fill(std::vector<int>& first, std::vector<int> second, int& count1) {
    if (count1 == 0) {
        for (int i = 0; i < 100; ++i) {
            first.push_back(i);
            second.push_back(i);
        }
    }
    else if (count1 == 1) {
        for (int i = 100; i < 1000; ++i) {
            first.push_back(i);
            second.push_back(i);
        }
    }
    else if (count1 == 2) {
        for (int i = 1000; i < 10000; ++i) {
            first.push_back(i);
            second.push_back(i);
        }
    }
    else if (count1 == 3) {
        for (int i = 10000; i < 100000; ++i) {
            first.push_back(i);
            second.push_back(i);
        }
    }
    else if (count1 == 4) {
        for (int i = 100000; i < 1000000; ++i) {
            first.push_back(i);
            second.push_back(i);
        }
        count1 = 0;
    }
    ++count1;
}

void processRange(std::vector<int>& first, std::vector<int>& second, int begin, int end) {
    int sum1 = 0, sum2 = 0;
    for (int i = begin; i < end; ++i) {
        sum1 += first[i];
        sum2 += first[i];
    }
}

void parallelExecution(std::vector<int>& first, std::vector<int>& second, int numThreads, std::chrono::high_resolution_clock::time_point& start, std::chrono::high_resolution_clock::time_point& finish, std::vector<std::chrono::duration<double>>& durations) {
    int totalIterations = first.size();
    int iterationsPerThread = totalIterations / numThreads;
    int remainingIterations = totalIterations % numThreads;

    std::vector<std::thread> threads;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numThreads; ++i) {
        int begin = i * iterationsPerThread;
        int end = begin + iterationsPerThread + (i < remainingIterations ? 1 : 0);
        threads.emplace_back(processRange, std::ref(first), std::ref(second), begin, end);
    }
    for (std::thread& thread : threads) {
        thread.join();
    }
    finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = finish - start;
    durations.push_back(duration);
}

void clearVectors(std::vector<int>& first, std::vector<int>& second) {
    first.clear();
    second.clear();
}

void whatStr(std::string& str, int temp) {

    if (temp == 0) {
        str = "Один поток: ";
    }
    else if (temp > 3 && temp < 8) {
        str = "Два потока: ";
    }

    else if (temp > 7 && temp < 12) {
        str = "Четыре потока: ";
    }
    else if (temp > 11 && temp < 16) {
        str = "В-мь потоков: ";
    }
    else if (temp > 15 && temp < 20) {
        str = "Ш-ть потоков: ";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string str;
    std::vector<std::chrono::duration<double>> durations;
    int count1 = 0, count2 = 0, streams = 0, temp = 0;
    auto start = std::chrono::high_resolution_clock::now();
    auto finish = std::chrono::high_resolution_clock::now();

    unsigned int nCores = std::thread::hardware_concurrency();
    std::cout << "Количество аппаратных ядер процессора: " << nCores << std::endl;

    std::vector<int> first, second;

    int numThreads = 1; 

    for (int i = 0; i < 4; ++i) {
        fill(first, second, count1);
        parallelExecution(first, second, numThreads, start, finish, durations);
    }
    clearVectors(first, second);

    for (int i = 0; i < 4; ++i) {
        fill(first, second, count1);
        parallelExecution(first, second, 2, start, finish, durations);
    }
    clearVectors(first, second);

    for (int i = 0; i < 4; ++i) {
        fill(first, second, count1);
        parallelExecution(first, second, 4, start, finish, durations);
    }
    clearVectors(first, second);

    for (int i = 0; i < 4; ++i) {
        fill(first, second, count1);
        parallelExecution(first, second, 8, start, finish, durations);
    }
    clearVectors(first, second);

    for (int i = 0; i < 4; ++i) {
        fill(first, second, count1);
        parallelExecution(first, second, 16, start, finish, durations);
    }
    clearVectors(first, second);

    std::cout << std::endl;
    std::cout << "\t\t1000\t\t" << "10000\t\t" << "100000\t\t" "1000000\t\t\n";

    for (const auto& dur : durations) {
        whatStr(str, temp);
        if (temp > 0 && temp % 4 == 0) {
            std::cout << std::endl;
        }
        if (temp == 0 || temp % 4 == 0) {
            std::cout << str << '\t' << std::fixed << dur.count() << "s";
        }
        else if (temp != 0) {
            std::cout << '\t' << std::fixed << dur.count() << "s";
        }

        ++temp;
    }
}



