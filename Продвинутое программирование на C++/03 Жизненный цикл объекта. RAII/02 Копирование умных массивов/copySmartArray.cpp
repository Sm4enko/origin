#include<iostream>

int COUNT = 0;

int SIZE = 0;

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

	int get_element(int index)

	{

		if (index >= 0 && index <= SIZE) {

			std::cout << arr[index];

		}

		else {

			throw("Error");

		}

		return index;

	}

	int return_element(int index)

	{

		if (index >= 0 && index <= SIZE) {

		}

		else {

			throw("Error");

		}

		return index;

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

	int temp = 0;

	std::cout << "¬ведите размер массива: ";

	std::cin >> SIZE;

	try {

		smart_array arr(SIZE);

		arr.add_element(1);

		arr.add_element(4);

		arr.add_element(155);

		arr.add_element(14);

		arr.add_element(15);

		arr.get_element(1);

		std::cout << std::endl;

		if (COUNT > SIZE) {

			throw ("Error");

		}

		COUNT = 0;

		std::cout << "¬ведите размер массива 2: ";

		std::cin >> SIZE;

		smart_array new_array(SIZE);

		new_array.add_element(44);

		new_array.add_element(34);

		new_array.get_element(1);

		if (COUNT > SIZE) {

			throw ("Error");

		}

		COUNT = 0;

		for (int i = 0; i < SIZE; ++i) {

			temp = new_array.return_element(i);

			arr.add_element(temp);

		}

		if (COUNT > SIZE) {

			throw ("Error");

		}

	}

	catch (const std::exception& ex) {

		std::cout << ex.what() << std::endl;

	}

	system("pause");

	return 0;

}