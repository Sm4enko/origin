#pragma once
#ifdef MATHPOWERLIBRARYDYNAMIC_EXPORTS
#define MATHPOWERLIBRARY_API 
#else
#define MATHPOWERLIBRARY_API 
#endif
#include "Quadrangle.h"

class Rectangle : public Quadrangle {
public:
	MATHPOWERLIBRARY_API Rectangle(int sides_count, std::string name);
};















