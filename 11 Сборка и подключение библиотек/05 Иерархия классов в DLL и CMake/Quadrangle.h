#pragma once

#include "Figure.h"

class Quadrangle : public Figure {
protected:
	int a, b, c, d, e, f, k, l;
public:
    Quadrangle(int sides_count, std::string name);

	void setNumber(int num);
    void setName(std::string n);
	void set_lenght_and_corners(int aa, int bb, int cc, int dd, int ee, int ff, int kk, int ll);
	int get_a();
	int get_b();
	int get_c();
	int get_d();
	int get_e();
	int get_f();
	int get_k();
	int get_l();
	void print_info();
};










