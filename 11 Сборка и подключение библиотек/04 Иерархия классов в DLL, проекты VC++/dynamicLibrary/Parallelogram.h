#pragma once
#ifdef MATHPOWERLIBRARYDYNAMIC_EXPORTS
#define MATHPOWERLIBRARY_API __declspec(dllexport)
#else
#define MATHPOWERLIBRARY_API __declspec(dllimport)
#endif



#include "Quadrangle.h"

class Parallelogram : public Quadrangle {
public:
	MATHPOWERLIBRARY_API Parallelogram(int sides_count, std::string name);
};





