#pragma once
#ifdef MATHPOWERLIBRARYDYNAMIC_EXPORTS
#define MATHPOWERLIBRARY_API 
#else
#define MATHPOWERLIBRARY_API 
#endif

#include "Triangle.h"

class equilateraltriangle : public Triangle {
public:
	MATHPOWERLIBRARY_API equilateraltriangle(int sides_count, std::string name);
};






