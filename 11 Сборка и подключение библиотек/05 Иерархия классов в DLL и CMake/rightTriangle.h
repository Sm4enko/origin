#pragma once
#ifdef MATHPOWERLIBRARYDYNAMIC_EXPORTS
#define MATHPOWERLIBRARY_API 
#else
#define MATHPOWERLIBRARY_API 
#endif
#include "Triangle.h"

class rightTriangle : public Triangle {
public:
	MATHPOWERLIBRARY_API rightTriangle(int sides_count, std::string name);
};








