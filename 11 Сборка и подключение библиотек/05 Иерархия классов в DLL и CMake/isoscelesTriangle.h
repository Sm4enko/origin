#pragma once
#ifdef MATHPOWERLIBRARYDYNAMIC_EXPORTS
#define MATHPOWERLIBRARY_API 
#else
#define MATHPOWERLIBRARY_API 
#endif
#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include "Triangle.h"

class isoscelesTriangle : public Triangle {
public:
	MATHPOWERLIBRARY_API isoscelesTriangle(int sides_count, std::string name);
};

#endif








