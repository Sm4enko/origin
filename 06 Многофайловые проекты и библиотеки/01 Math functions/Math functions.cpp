#include <iostream>
#include "math_power.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	int x, y, s;
	std::cout << "������� ������ �����: ";
	std::cin >> x;
	std::cout << "������� ������ �����: ";
	std::cin >> y;
		std::cout << "1 - ��������, 2 ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������: ";
		std::cin >> s;
		if (s == 1) {
			std::cout << x << " ���� " << y << " = " << plus(x, y);
		}
		else if (s == 2) {
			std::cout << x << " ����� " << y << " = " << minus(x, y);
		}
		else if (s == 3) {
			std::cout << x << " �������� �� " << y << " = " << multi(x, y);
		}
		else if (s == 4) {
			std::cout << x << " ��������� �� " << y << " = " << division(x, y);
		}
		else if (s == 5) {
			std::cout << x << " � ������� " << y << " = " << degree(x, y);
		}

}
