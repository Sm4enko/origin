#pragma once
#ifdef MATHPOWERLIBRARYDYNAMIC_EXPORTS
#define MATHPOWERLIBRARY_API __declspec(dllexport)
#else
#define MATHPOWERLIBRARY_API __declspec(dllimport)
#endif

#include "Figure.h"

class Quadrangle : public Figure {
protected:
	int a, b, c, d, e, f, k, l;
public:
	MATHPOWERLIBRARY_API Quadrangle(int sides_count, std::string name);

	MATHPOWERLIBRARY_API void setNumber(int num);
	MATHPOWERLIBRARY_API void setName(std::string n);
	MATHPOWERLIBRARY_API void set_lenght_and_corners(int aa, int bb, int cc, int dd, int ee, int ff, int kk, int ll);
	MATHPOWERLIBRARY_API int get_a();
	MATHPOWERLIBRARY_API int get_b();
	MATHPOWERLIBRARY_API int get_c();
	MATHPOWERLIBRARY_API int get_d();
	MATHPOWERLIBRARY_API int get_e();
	MATHPOWERLIBRARY_API int get_f();
	MATHPOWERLIBRARY_API int get_k();
	MATHPOWERLIBRARY_API int get_l();
	MATHPOWERLIBRARY_API void print_info();
};










