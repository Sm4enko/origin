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

void oneThread(std::vector<int> first, std::vector<int> second, std::chrono::high_resolution_clock::time_point& start, std::chrono::high_resolution_clock::time_point& finish, std::vector<std::chrono::duration<double>>& durations) {
    start = std::chrono::high_resolution_clock::now();
    int sum1 = 0, sum2 = 0;


    for (int i = 0; +i < first.size(); ++i) {
        sum1 += first[i];
    }
    for (int j = 0; j < second.size(); ++j) {
        sum2 += second[j];
    }
    finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = finish - start;
    durations.push_back(duration);
}

void sum21(const std::vector<int> first, const std::vector<int> second, const int streams) {
   
    int sum1 = 0;

   
        for (int i = 0; i < first.size(); ++i) {
            sum1 += first[i];
        }
}

void sum22(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum2 = 0;


    for (int i = 0; i < first.size(); ++i) {
        sum2 += first[i];
    }
}

void sum41(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum1 = 0;


    for (int i = 0; i < first.size() / 2; ++i) {
        sum1 += first[i];
    }
}

void sum42(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum1 = 0;


    for (int i = first.size() / 2; i < first.size(); ++i) {
        sum1 += first[i];
    }
}

void sum43(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum1 = 0;


    for (int i = 0; i < second.size() / 2; ++i) {
        sum1 += second[i];
    }
}

void sum44(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum1 = 0;


    for (int i = second.size() / 2; i < second.size(); ++i) {
        sum1 += second[i];
    }
}

void sum81(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum1 = 0;


    for (int i = 0; i < first.size() / 4 + 1; ++i) {
        sum1 += first[i];
    }
}

void sum82(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum1 = 0;


    for (int i = first.size() / 4 + 1; i < first.size() / 2; ++i) {
        sum1 += first[i];
    }
}

void sum83(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum1 = 0;


    for (int i = 0; i < first.size() / 4 + 1; ++i) {
        sum1 += first[i];
    }
}

void sum84(const std::vector<int> first, const std::vector<int> second, const int streams) {
    int sum1 = 0;


    for (int i = first.size() / 4 + 1; i < first.size() / 2; ++i) {
        sum1 += first[i];
    }
}

void sum85(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum1 = 0;


    for (int i = 0; i < second.size() / 4 + 1; ++i) {
        sum1 += first[i];
    }
}

void sum86(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum1 = 0;


    for (int i = first.size() / 4 + 1; i < first.size() / 2; ++i) {
        sum1 += first[i];
    }
}

void sum87(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum1 = 0;


    for (int i = 0; i < first.size() / 4 + 1; ++i) {
        sum1 += first[i];
    }
}

void sum88(const std::vector<int> first, const std::vector<int> second, const int streams) {
    int sum1 = 0;


    for (int i = first.size() / 4 + 1; i < first.size() / 2; ++i) {
        sum1 += first[i];
    }
}

void sum161(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum1 = 0;


    for (int i = 0; i < first.size() / 8; ++i) {
        sum1 += first[i];
    }
}

void sum162(const std::vector<int> first, const std::vector<int> second, const int streams) {

    int sum1 = 0;


    for (int i = first.size() / 8; i < first.size() / 4 + 1; ++i) {
        sum1 += first[i];
    }
}

void clearVectors(std::vector<int>& first, std::vector<int>& second) {
    first.clear();
    second.clear();
}

void twoThreads(std::vector<int> first, std::vector<int> second, int& count1, int& count2, std::chrono::high_resolution_clock::time_point& start, std::chrono::high_resolution_clock::time_point& finish, std::vector<std::chrono::duration<double>>& durations, int& streams) {
    start = std::chrono::high_resolution_clock::now();
    std::thread t1(sum21, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t2(sum22, std::ref(first), std::ref(second), std::ref(streams));
    t1.join();
    t2.join();
    finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);
    durations.push_back(duration);
}

void fourThreads(std::vector<int> first, std::vector<int> second, int& count1, int& count2, std::chrono::high_resolution_clock::time_point& start, std::chrono::high_resolution_clock::time_point& finish, std::vector<std::chrono::duration<double>>& durations, int& streams) {
    start = std::chrono::high_resolution_clock::now();
    std::thread t1(sum41, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t2(sum42, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t3(sum43, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t4(sum44, std::ref(first), std::ref(second), std::ref(streams));
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);
    durations.push_back(duration);
}

void eightThreads(std::vector<int> first, std::vector<int> second, int& count1, int& count2, std::chrono::high_resolution_clock::time_point& start, std::chrono::high_resolution_clock::time_point& finish, std::vector<std::chrono::duration<double>>& durations, int& streams) {
    start = std::chrono::high_resolution_clock::now();
    std::thread t1(sum81, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t2(sum82, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t3(sum83, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t4(sum84, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t5(sum85, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t6(sum86, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t7(sum87, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t8(sum88, std::ref(first), std::ref(second), std::ref(streams));
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);
    durations.push_back(duration);
}

void sixTThreads(std::vector<int> first, std::vector<int> second, int& count1, int& count2, std::chrono::high_resolution_clock::time_point& start, std::chrono::high_resolution_clock::time_point& finish, std::vector<std::chrono::duration<double>>& durations, int& streams) {
    start = std::chrono::high_resolution_clock::now();
    std::thread t1(sum161, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t2(sum162, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t3(sum161, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t4(sum162, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t5(sum161, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t6(sum162, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t7(sum161, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t8(sum162, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t9(sum161, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t10(sum162, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t11(sum161, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t12(sum162, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t13(sum161, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t14(sum162, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t15(sum161, std::ref(first), std::ref(second), std::ref(streams));
    std::thread t16(sum162, std::ref(first), std::ref(second), std::ref(streams));
   
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    t12.join();
    t13.join();
    t14.join();
    t15.join();
    t16.join();
    finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);
    durations.push_back(duration);
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

    for (int i = 0; i < 4; ++i) {
        fill(first, second, count1);
        oneThread(first, second, start, finish, durations);
    }
    clearVectors(first, second);

    for (int i = 0; i < 4; ++i) {
        fill(first, second, count1);
        twoThreads(first, second, count1, count2, start, finish, durations, streams);
    }
    clearVectors(first, second);

    for (int i = 0; i < 4; ++i) {
        fill(first, second, count1);
        fourThreads(first, second, count1, count2, start, finish, durations, streams);
    }
    clearVectors(first, second);

    for (int i = 0; i < 4; ++i) {
        fill(first, second, count1);
        eightThreads(first, second, count1, count2, start, finish, durations, streams);
    }
    clearVectors(first, second);

    for (int i = 0; i < 4; ++i) {
        fill(first, second, count1);
        sixTThreads(first, second, count1, count2, start, finish, durations, streams);
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



