#include <iostream>
#define MODE 1

int add(int a, int b) {
	
	return a + b;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
#ifndef MODE
#error Define mode
#endif
#if MODE == 0
	std::cout << "������� � ������ ����������" << std::endl;
#elif MODE == 1
	std::cout << "������� � ������ ������" << std::endl;
	std::cout << "������� ����� 1: \n";
	std::cin >> a;
	std::cout << "������� ����� 2: \n";
	std::cin >> b;
	std::cout << "��������� ��������: " << add(a, b);
#else
	std::cout << "����������� �����. ���������� ������" << std::endl;
#endif
}


