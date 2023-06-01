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
	std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
	std::cout << "Работаю в боевом режиме" << std::endl;
	std::cout << "Введите число 1: \n";
	std::cin >> a;
	std::cout << "Введите число 2: \n";
	std::cin >> b;
	std::cout << "Результат сложения: " << add(a, b);
#else
	std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif
}


