#include<iostream>



class smart_array



{


private:



    int* arr;



    int N;

    

    int count;



public:

    smart_array(const smart_array&) = delete;

    smart_array& operator=(const smart_array& other)

    {
        if (this != &other)

        {
            delete[] arr;

            N = other.N;

            count = other.count;

            arr = new int[N];

            for (int i = 0; i < N; ++i)

            {
                arr[i] = other.arr[i];

            }

        }

        return *this;

    }

    

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


        if (index < 0 && index > N) {


            throw("Error");



        }





        return arr[index];



    }



    int return_element(int index)



    {


        if (index >= 0 && index <= N) {


        }



        else {


            throw("Error");



        }



        return index;



    }



    void add_element(int number)



    {
        if (count < 0 || count >= N) {
            throw("Error");

        }

        arr[count] = number;



        ++count;



    }



};



int main()



{


    setlocale(LC_ALL, "Russian");

    

    int size;

    

    int count = 0;



    int temp = 0;



    std::cout << "Введите размер массива: ";



    std::cin >> size;



    try {


        smart_array arr(size, count);



        arr.add_element(1);



        arr.add_element(4);



        arr.add_element(155);



        arr.add_element(14);



        arr.add_element(15);



        std::cout << arr.get_element(1);



        std::cout << std::endl;



        if (count > size) {


            throw ("Error");



        }



        count = 0;



        std::cout << "Введите размер массива: ";



        std::cin >> size;



        smart_array new_array(size, count);



        new_array.add_element(44);



        new_array.add_element(34);



        std::cout << new_array.get_element(1);



        if (count > size) {


            throw ("Error");



        }



        count = 0;



        for (int i = 0; i < size; ++i) {


            temp = new_array.return_element(i);



            arr.add_element(temp);



        }



        if (count > size) {


            throw ("Error");



        }



    }



    catch (const std::exception& ex) {


        std::cout << ex.what() << std::endl;



    }



    system("pause");



    return 0;



}
