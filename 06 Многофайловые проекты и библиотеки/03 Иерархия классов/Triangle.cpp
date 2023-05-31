#include "Triangle.h"

Triangle::Triangle(int sides_count, std::string name) : Figure(sides_count, name) {}

void Triangle::setNumber(int num) {
	sides_count = num;
}

void Triangle::setName(std::string n) {
	name = n;
}

void Triangle::set_lenght_and_corners(int aa, int bb, int cc, int dd, int ee, int ff) {
	a = aa;
	b = bb;
	c = cc;
	d = dd;
	e = ee;
	f = ff;
}

int Triangle::get_a() {
	return a;
}

int Triangle::get_b() {
	return b;
}

int Triangle::get_c() {
	return c;
}

int Triangle::get_d() {
	return d;
}

int Triangle::get_e() {
	return e;
}

int Triangle::get_f() {
	return f;
}

void Triangle::print_info() {
	std::cout << what() << "Стороны: " << "a = " << get_a() << " b = " << get_b() << " c = " << get_c() << std::endl << "Углы:" << " A = " << get_d() << " B = " << get_e() << " C = " << get_f() << std::endl;
}
