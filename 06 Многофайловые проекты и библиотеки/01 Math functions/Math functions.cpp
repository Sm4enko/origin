#include <iostream>
#include "math_power.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	int x, y, s;
	std::cout << "Введите первое число: ";
	std::cin >> x;
	std::cout << "Введите второе число: ";
	std::cin >> y;
		std::cout << "1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень: ";
		std::cin >> s;
		if (s == 1) {
			std::cout << x << " плюс " << y << " = " << plus(x, y);
		}
		else if (s == 2) {
			std::cout << x << " минус " << y << " = " << minus(x, y);
		}
		else if (s == 3) {
			std::cout << x << " умножить на " << y << " = " << multi(x, y);
		}
		else if (s == 4) {
			std::cout << x << " разделить на " << y << " = " << division(x, y);
		}
		else if (s == 5) {
			std::cout << x << " в степени " << y << " = " << degree(x, y);
		}

}
