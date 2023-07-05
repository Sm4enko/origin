#pragma once

#include "Figure.h"

class Triangle : public Figure {
protected:
    int a, b, c, d, e, f;
public:
	MATHPOWERLIBRARY_API Triangle(int sides_count, std::string name);

	MATHPOWERLIBRARY_API void setNumber(int num);
	MATHPOWERLIBRARY_API void setName(std::string n);
	MATHPOWERLIBRARY_API void set_lenght_and_corners(int aa, int bb, int cc, int dd, int ee, int ff);
	MATHPOWERLIBRARY_API int get_a();
	MATHPOWERLIBRARY_API int get_b();
	MATHPOWERLIBRARY_API int get_c();
	MATHPOWERLIBRARY_API int get_d();
	MATHPOWERLIBRARY_API int get_e();
	MATHPOWERLIBRARY_API int get_f();
	MATHPOWERLIBRARY_API void print_info();
};







