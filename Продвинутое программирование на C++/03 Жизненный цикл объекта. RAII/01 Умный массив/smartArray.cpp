#include<iostream>

class smart_array

{

private:

    int* arr;

    int N;
    
    int count;

public:

    smart_array(const smart_array&) = delete;
    smart_array& operator=(const smart_array&) = delete;
    smart_array(int n, int& count)

    {

        N = n;

        arr = new int[N];
        
        this->count = count;

    }

    ~smart_array()

    {

        delete[]arr;

    }

    int getsize()

    {

        return N;

    }

    int get_element(int index)

    {

        if (index <= 0 || index >= count) {

            throw("Error");
        }
        return arr[index];

    }

    void add_element(int number)

    {
        if (count < 0 || count > N) {
            throw("Error");
        }
        arr[count] = number;

        ++count;

    }

};

int main()

{

    setlocale(LC_ALL, "Russian");

    int n;
    int count = 0;

    std::cout << "Ââåäèòå ðàçìåð ìàññèâà: ";

    std::cin >> n;

    try {

        smart_array arr(n, count);

        arr.add_element(1);

        arr.add_element(4);

        arr.add_element(155);

        arr.add_element(14);

        arr.add_element(15);

        std::cout << arr.get_element(1);

        std::cout << std::endl;

        if (count > n) {

            throw ("Error");

        }

    }

    catch (const std::exception& ex) {

        std::cout << ex.what() << std::endl;

    }

    system("pause");

    return 0;

}
