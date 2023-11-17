#include <iostream>
#include <thread>
#include <mutex>
#include <algorithm>

template <typename T>
class Data {
private:
    std::mutex mtx1;
    std::mutex mtx2;
    T a, b;

public:
    Data() : a(30), b(50) {}

    void Lock() {
        mtx1.lock();
        mtx2.lock();
    }

    void Unlock() {
        mtx1.unlock();
        mtx2.unlock();
    }

    T GetData1() {
        return a;
    }

    T GetData2() {
        return b;
    }

    void SetData1(T value) {
        a = value;
    }

    void SetData2(T value2) {
        b = value2;
    }

    void swap(T value1, T value2) {
        std::lock(mtx1, mtx2);
        std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
        std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);

        SetData1(value2);
        SetData2(value1);
    }

    void swap2(T value1, T value2) {
        std::lock(mtx1, mtx2);
        std::unique_lock<std::mutex> lock1(mtx1, std::adopt_lock);
        std::unique_lock<std::mutex> lock2(mtx2, std::adopt_lock);
        SetData1(value2);
        SetData2(value1);
    }

    void swap3(T value1, T value2) {
        std::scoped_lock lock(mtx1, mtx2);
        SetData1(value2);
        SetData2(value1);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Data<int> myMutexObject;

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
