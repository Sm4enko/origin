#include <iostream>
#include <thread>
#include <mutex>
#include <algorithm>

class myMutex {
private:
    std::mutex mtx1;
    std::mutex mtx2;
    int a = 30, b = 50;

public:
    myMutex() : a(0), b(0) {}

    void Lock() {
        mtx1.lock();
        mtx2.lock();
    }

    void Unlock() {
        mtx1.unlock();
        mtx2.unlock();
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
        std::unique_lock<std::mutex> lock(mtx1);
        SetData1(value2);
        SetData2(value1);
    }

    void swap3(int value1, int value2) {
        std::lock(mtx1, mtx2);
        std::unique_lock<std::mutex> lock1(mtx1, std::adopt_lock);
        std::unique_lock<std::mutex> lock2(mtx2, std::adopt_lock);
        SetData1(value2);
        SetData2(value1);
    }

};

int main() {
    setlocale(LC_ALL, "Russian");
    myMutex myMutexObject;

    std::thread t1([&myMutexObject]() {
        int value1 = 42, value2 = 10;
        myMutexObject.swap(value1, value2);
        std::cout << "Первый поток: " << myMutexObject.GetData1() << ", " << myMutexObject.GetData2() << std::endl;
        });

    std::thread t2([&myMutexObject]() {
        int value1 = myMutexObject.GetData1();
        int value2 = myMutexObject.GetData2();
        myMutexObject.swap2(value1, value2);
        std::cout << "Второй поток: " << myMutexObject.GetData1() << ", " << myMutexObject.GetData2() << std::endl;
        });

    std::thread t3([&myMutexObject]() {
        int value1 = myMutexObject.GetData1();
        int value2 = myMutexObject.GetData2();
        myMutexObject.swap3(value1, value2);
        std::cout << "Третий поток: " << myMutexObject.GetData1() << ", " << myMutexObject.GetData2() << std::endl;
        });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
