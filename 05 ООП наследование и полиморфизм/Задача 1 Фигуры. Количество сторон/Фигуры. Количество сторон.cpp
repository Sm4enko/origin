#include <iostream>
#include <string>


class Figure {
protected:
	int sides_count;
	std::string name;
public:

	Figure(int num, std::string n) : sides_count(num), name(n) {}

	int get_sides_count() {
		return sides_count;
	}
	std::string what() {
		return name;
	}
	void display() {
		std::cout << what() << get_sides_count() << std::endl;
	}
};


class Triangle : public Figure {
public:
	Triangle(int sides_count, std::string name) : Figure(sides_count, name) {}

	void setNumber(int num) {
		sides_count = num;
	}
	void setName(std::string n) {
		name = n;
	}

	void display() {
		std::cout << what() << get_sides_count() << std::endl;
	}
};


class Quadrangle : public Figure {
public:
	Quadrangle(int sides_count, std::string name) : Figure(sides_count, name) {}

	void setNumber(int num) {
		sides_count = num;
	}
	void setName(std::string n) {
		name = n;
	}

	void display() {
		std::cout << what() << get_sides_count() << std::endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Количество сторон: \n";
	Figure figure(0, "Фигура: ");
	figure.display();
	Triangle triangle(3, "Треугольник: ");
	triangle.display();
	Quadrangle quadrangle(4, "Квадрат: ");
	quadrangle.display();




}

