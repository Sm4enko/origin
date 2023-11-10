#include <chrono>
#include <iostream>
#include <thread>
#include <atomic>

void Client(std::atomic<int>& Counter, std::atomic<int>& People) {
    while (People.load() > 0) {
        --People;
        Counter.fetch_add(1, std::memory_order_relaxed);
        std::cout << "+1\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void Teller(std::atomic<int>& Counter, std::atomic<int>& People2) {
    while (People2.load() > 0) {
        --People2;
        std::cout << "-1\n";
        Counter.fetch_sub(1, std::memory_order_relaxed);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::atomic<int> Counter(0);
    int howMuch;

    std::cout << "Введите количество клиентов: ";
    std::cin >> howMuch;
    std::atomic<int> P1(howMuch);
    std::atomic<int> P2(howMuch);

    std::thread t1(Client, std::ref(Counter), std::ref(P1));
    std::thread t2(Teller, std::ref(Counter), std::ref(P2));

    t1.join();
    t2.join();

    std::cout << "\nИтого: " << Counter.load(std::memory_order_relaxed) << std::endl;
}
