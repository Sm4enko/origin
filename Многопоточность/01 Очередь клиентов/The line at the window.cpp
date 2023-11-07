#include <chrono>
#include <iostream>
#include <thread>


void Client(int& Counter, int& People) {

    while (People > 0) {
        --People;
        ++Counter;
        std::cout << "+1\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void Teller(int& Counter, int& People2) {

    while (People2 > 0) {
        --People2;
        std::cout << "-2\n";
        --Counter;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int Сounter = 0;
    int People, People2;

    std::cout << "Введите количество клиентов: ";
    std::cin >> People;
    People2 = People;
  
    std::thread t1(Client, std::ref(Сounter), std::ref(People));
    std::thread t2(Teller, std::ref(Сounter), std::ref(People2));
    
    t1.join();
    t2.join();

    std::cout << "\nИтого: " << Сounter;
}


