#include<iostream>

int COUNT = 0;

class smart_array

{

private:

	int* arr;

	int N;

public:

	smart_array(int n)

	{

		N = n;

		arr = new int[N];

	}

	~smart_array()

	{

		delete[]arr;

	}

	int getsize()

	{

		return N;

	}

	void get_element(int index)

	{

		if (index >= 0 || index <= COUNT) {

			std::cout << arr[index];

		}

	}

	void add_element(int number)

	{

		arr[COUNT] = number;

		++COUNT;

	}

};

int main()

{

	setlocale(LC_ALL, "Russian");

	int n;

	std::cout << "¬ведите размер массива: ";

	std::cin >> n;

	try {

		smart_array arr(n);

		arr.add_element(1);

		arr.add_element(4);

		arr.add_element(155);

		arr.add_element(14);

		arr.add_element(15);

		arr.get_element(1);

		std::cout << std::endl;

		if (COUNT > n) {

			throw ("Error");

		}

	}

	catch (const std::exception& ex) {

		std::cout << ex.what() << std::endl;

	}

	system("pause");

	return 0;

}