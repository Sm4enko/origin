#include "equilateraltriangle.h"

equilateraltriangle::equilateraltriangle(int sides_count, std::string name) : Triangle(sides_count, name) {
	if (a != b || a != c || b != c || d != 60 || e != 60 || f != 60) {
		throw "Условия не соблюдены";
	}
}
