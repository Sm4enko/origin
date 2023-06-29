#include "Quadrangle.h"

Quadrangle::Quadrangle(int sides_count, std::string name) : Figure(sides_count, name) {}

void Quadrangle::setNumber(int num) {
	sides_count = num;
}

void Quadrangle::setName(std::string n) {
	name = n;
}

void Quadrangle::set_lenght_and_corners(int aa, int bb, int cc, int dd, int ee, int ff, int kk, int ll) {
	a = aa;
	b = bb;
	c = cc;
	d = dd;
	e = ee;
	f = ff;
	k = kk;
	l = ll;
}

int Quadrangle::get_a() {
	return a;
}

int Quadrangle::get_b() {
	return b;
}

int Quadrangle::get_c() {
	return c;
}

int Quadrangle::get_d() {
	return d;
}

int Quadrangle::get_e() {
	return e;
}

int Quadrangle::get_f() {
	return f;
}

int Quadrangle::get_k() {
	return k;
}

int Quadrangle::get_l() {
	return l;
}

void Quadrangle::print_info() {
	std::cout << what() << "Стороны: " << "a = " << get_a() << " b = " << get_b() << " c = " << get_c() << " d = " << get_d() << std::endl << "Углы:" << " A = " << get_e() << " B = " << get_f() << " C = " << get_k() << " D = " << get_l() << std::endl;
}
