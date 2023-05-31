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
	void print_info() {
		std::cout << what() << "Сторон: " << get_sides_count() << std::endl;
	}
	virtual bool check() {
		return true;
	}
};

class Triangle : public Figure {
protected:
	int a, b, c, d, e, f;
public:
	Triangle(int sides_count, std::string name) : Figure(sides_count, name) {}

	void set_lenght_and_corners(int aa, int bb, int cc, int dd, int ee, int ff) {
		a = aa;
		b = bb;
		c = cc;
		d = dd;
		e = ee;
		f = ff;
	}
	int get_a() {
		return a;
	}
	int get_b() {
		return b;
	}
	int get_c() {
		return c;
	}
	int get_d() {
		return d;
	}
	int get_e() {
		return e;
	}
	int get_f() {
		return f;
	}
	void print_info() {
		std::cout << what() << "Стороны: a = " << get_a() << ", b = " << get_b() << ", c = " << get_c() << std::endl;
		std::cout << "Углы: A = " << get_d() << ", B = " << get_e() << ", C = " << get_f() << std::endl;
	}
};

class Quadrangle : public Figure {
protected:
	int a, b, c, d, e, f, k, l;
public:
	Quadrangle(int sides_count, std::string name) : Figure(sides_count, name) {}

	void set_lenght_and_corners(int aa, int bb, int cc, int dd, int ee, int ff, int kk, int ll) {
		a = aa;
		b = bb;
		c = cc;
		d = dd;
		e = ee;
		f = ff;
		k = kk;
		l = ll;
	}
	int get_a() {
		return a;
	}
	int get_b() {
		return b;
	}
	int get_c() {
		return c;
	}
	int get_d() {
		return d;
	}
	int get_e() {
		return e;
	}
	int get_f() {
		return f;
	}
	int get_k() {
		return k;
	}
	int get_l() {
		return l;
	}
	void print_info() {
		std::cout << what() << "Стороны: a = " << get_a() << ", b = " << get_b() << ", c = " << get_c() << ", d = " << get_d() << std::endl;
		std::cout << "Углы: A = " << get_e() << ", B = " << get_f() << ", C = " << get_k() << ", D = " << get_l() << std::endl;
	}
};

class rightTriangle : public Triangle {
public:
	rightTriangle(int sides_count, std::string name) : Triangle(sides_count, name) {}
	bool check() override {
		return true;
	}
};

class isoscelesTriangle : public Triangle {
public:
	isoscelesTriangle(int sides_count, std::string name) : Triangle(sides_count, name) {}
	bool check() override {
		return true;
	}
};

class equilateraltriangle : public Triangle {
public:
	equilateraltriangle(int sides_count, std::string name) : Triangle(sides_count, name) {}
	bool check() override {
		return true;
	}
};

class Rectangle : public Quadrangle {
public:
	Rectangle(int sides_count, std::string name) : Quadrangle(sides_count, name) {}
	bool check() override {
		return true;
	}
};

class Square : public Quadrangle {
public:
	Square(int sides_count, std::string name) : Quadrangle(sides_count, name) {}
	bool check() override {
		return true;
	}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int sides_count, std::string name) : Quadrangle(sides_count, name) {}
	bool check() override {
		return false;
	}
};

class Rhombus : public Quadrangle {
public:
	Rhombus(int sides_count, std::string name) : Quadrangle(sides_count, name) {}
	bool check() override {
		return false;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Figure* figure;
	figure = new Triangle(3, "Треугольник: ");
	figure->set_lenght_and_corners(10, 20, 30, 50, 60, 70);
	if (figure->check() == false) {
		std::cout << "Неправильный ";
	}
	else {
		std::cout << "Правильный ";
	}
	figure->print_info();
	delete figure;

	figure = new rightTriangle(3, "Прямоугольный треугольник: ");
	figure->set_lenght_and_corners(10, 20, 30, 50, 60, 90);
	if (figure->check() == false) {
		std::cout << "Неправильный ";
	}
	else {
		std::cout << "Правильный ";
	}
	figure->print_info();
	delete figure;

	figure = new isoscelesTriangle(3, "Равнобедренный треугольник: ");
	figure->set_lenght_and_corners(10, 20, 10, 50, 60, 50);
	if (figure->check() == false) {
		std::cout << "Неправильный ";
	}
	else {
		std::cout << "Правильный ";
	}
	figure->print_info();
	delete figure;

	figure = new Quadrangle(4, "Четырехугольник: ");
	figure->set_lenght_and_corners(10, 20, 30, 40, 50, 60, 70, 80);
	if (figure->check() == false) {
		std::cout << "Неправильный ";
	}
	else {
		std::cout << "Правильный ";
	}
	figure->print_info();
	delete figure;

	figure = new Rectangle(4, "Прямоугольник: ");
	figure->set_lenght_and_corners(10, 20, 10, 20, 90, 90, 90, 90);
	if (figure->check() == false) {
		std::cout << "Неправильный ";
	}
	else {
		std::cout << "Правильный ";
	}
	figure->print_info();
	delete figure;

	figure = new Square(4, "Квадрат: ");
	figure->set_lenght_and_corners(20, 20, 20, 20, 90, 90, 90, 90);
	if (figure->check() == false) {
		std::cout << "Неправильный ";
	}
	else {
		std::cout << "Правильный ";
	}
	figure->print_info();
	delete figure;

	figure = new Parallelogram(4, "Параллелограм: ");
	figure->set_lenght_and_corners(20, 30, 20, 30, 30, 40, 30, 40);
	if (figure->check() == false) {
		std::cout << "Неправильный ";
	}
	else {
		std::cout << "Правильный ";
	}
	figure->print_info();
	delete figure;

	figure = new Rhombus(4, "Ромб: ");
	figure->set_lenght_and_corners(30, 30, 30, 30, 30, 40, 30, 40);
	if (figure->check() == false) {
		std::cout << "Неправильный ";
	}
	else {
		std::cout << "Правильный ";
	}
	figure->print_info();
	delete figure;

	return 0;
