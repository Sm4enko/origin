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
		std::cout << what() << get_sides_count() << std::endl;
	}
};


class Triangle : public Figure {
protected:
	int a, b, c, d, e, f;
public:
	Triangle(int sides_count, std::string name) : Figure(sides_count, name) {}

	void setNumber(int num) {
		sides_count = num;
	}
	void setName(std::string n) {
		name = n;
	}

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
		std::cout << what() << "Стороны: " << "a = " << get_a() << " b = " << get_b() << " c = " << get_c() << std::endl << "Углы:" << " A = " << get_d() << " B = " << get_e() << " C = " << get_f() << std::endl;
	}
};


class Quadrangle : public Figure {
protected:
	int a, b, c, d, e, f, k, l;
public:
	Quadrangle(int sides_count, std::string name) : Figure(sides_count, name) {}

	void setNumber(int num) {
		sides_count = num;
	}
	void setName(std::string n) {
		name = n;
	}

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
		std::cout << what() << "Стороны: " << "a = " << get_a() << " b = " << get_b() << " c = " << get_c() << " d = " << get_d() << std::endl << "Углы:" << " A = " << get_e() << " B = " << get_f() << " C = " << get_k() << " D = " << get_l() << std::endl;
	}
};

class rightTriangle : public Triangle {

public:
	rightTriangle(int sides_count, std::string name) : Triangle(sides_count, name) {}


};

class isoscelesTriangle : public Triangle {

public:
	isoscelesTriangle(int sides_count, std::string name) : Triangle(sides_count, name) {}


};

class equilateraltriangle : public Triangle {

public:
	equilateraltriangle(int sides_count, std::string name) : Triangle(sides_count, name) {}



};

class Rectangle : public Quadrangle {

public:
	Rectangle(int sides_count, std::string name) : Quadrangle(sides_count, name) {}

};

class Square : public Quadrangle {

public:
	Square(int sides_count, std::string name) : Quadrangle(sides_count, name) {}

};


class Parallelogram : public Quadrangle {

public:
	Parallelogram(int sides_count, std::string name) : Quadrangle(sides_count, name) {}

};

class Rhombus : public Quadrangle {

public:
	Rhombus(int sides_count, std::string name) : Quadrangle(sides_count, name) {}

};



int main()
{
	setlocale(LC_ALL, "Russian");

	Triangle triangle(3, "Треугольник: \n");
	triangle.set_lenght_and_corners(10, 20, 30, 50, 60, 70);
	triangle.print_info();

	rightTriangle rightTriangle(3, "Прямоугольный треугольник:\n");
	rightTriangle.set_lenght_and_corners(10, 20, 30, 50, 60, 90);
	rightTriangle.print_info();

	isoscelesTriangle isoscelesTriangle(3, "Равнобедренный треугольник: \n");
	isoscelesTriangle.set_lenght_and_corners(10, 20, 10, 50, 60, 50);
	isoscelesTriangle.print_info();

	equilateraltriangle equilateraltriangle(3, "Равносторонний треугольник: \n");
	equilateraltriangle.set_lenght_and_corners(30, 30, 30, 60, 60, 60);
	equilateraltriangle.print_info();

	Quadrangle quadrangle(4, "Четырехугольник: \n");
	quadrangle.set_lenght_and_corners(10, 20, 30, 40, 50, 60, 70, 80);
	quadrangle.print_info();

	Rectangle rectangle(4, "Прямоугольник: \n");
	rectangle.set_lenght_and_corners(10, 20, 10, 20, 90, 90, 90, 90);
	rectangle.print_info();

	Square square(4, "Квадрат: \n");
	square.set_lenght_and_corners(20, 20, 20, 20, 90, 90, 90, 90);
	square.print_info();

	Parallelogram parallelogram(4, "Параллелограм: \n");
	parallelogram.set_lenght_and_corners(20, 30, 20, 30, 30, 40, 30, 40);
	parallelogram.print_info();

	Rhombus rhombus(4, "Ромб: \n");
	rhombus.set_lenght_and_corners(30, 30, 30, 30, 30, 40, 30, 40);
	rhombus.print_info();




}

