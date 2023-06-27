#pragma once
#include "Figure.h"

class Triangle : public Figure {
protected:
	int a, b, c, d, e, f;
public:
	Triangle(int sides_count, std::string name);

	void setNumber(int num);
	void setName(std::string n);
	void set_lenght_and_corners(int aa, int bb, int cc, int dd, int ee, int ff);
	int get_a();
	int get_b();
	int get_c();
	int get_d();
	int get_e();
	int get_f();
	void print_info();
};


