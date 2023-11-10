#include <iostream>
#include <thread>
#include <mutex>
#include <algorithm>

class myMutex {
private:
    std::mutex mtx;
    std::mutex mtx1;
    int a = 30, b= 50;
public:
    myMutex() : a(0), b(0) {}

    void Lock() {
        mtx.lock();
    }

    void Unlock() {
        mtx.unlock();
    }

    int GetData1() {
        return a;
    }

    int GetData2() {
        return b;
    }

    void SetData1(int value) {
        a = value;
    }

    void SetData2(int value2) {
        b = value2;
    }

    void swap(int value1, int value2) {
        Lock();
        SetData1(value2);
        SetData2(value1);
        Unlock();
    }

    void swap2(int value1, int value2) {
        std::unique_lock<std::mutex> lock(mtx);
        SetData1(value2);
        SetData2(value1);
    }

    void swap3(int value1, int value2) {
    std::scoped_lock lock(mtx, mtx1); 
    SetData1(value2);
    SetData2(value1);

}

};

int main() {
    setlocale(LC_ALL, "Russian");
    myMutex myMutex;

    std::thread t1([&myMutex]() {
        int a = 42, b = 10;
        myMutex.swap(a, b);
        std::cout << "Первый поток: " << myMutex.GetData1() << ", " << myMutex.GetData2() << std::endl;
        });

    std::thread t2([&myMutex]() {
        int a = myMutex.GetData1();
        int b = myMutex.GetData2();
        myMutex.swap2(a, b);
        std::cout << "Второй поток: " << myMutex.GetData1() << ", " << myMutex.GetData2() << std::endl;
        });

    std::thread t3([&myMutex]() {
        int a = myMutex.GetData1();
        int b = myMutex.GetData2();
        myMutex.swap3(a, b);
        std::cout << "Третий поток: " << myMutex.GetData1() << ", " << myMutex.GetData2() << std::endl;
        });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
