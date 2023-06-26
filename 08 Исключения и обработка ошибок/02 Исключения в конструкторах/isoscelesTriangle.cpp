#include "isoscelesTriangle.h"

isoscelesTriangle::isoscelesTriangle(int sides_count, std::string name) : Triangle(sides_count, name) {
	if (a != c || d != f) {
		throw "Условия не соблюдены";
	}
}
