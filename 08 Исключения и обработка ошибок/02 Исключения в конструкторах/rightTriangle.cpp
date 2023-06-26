#include "rightTriangle.h"

rightTriangle::rightTriangle(int sides_count, std::string name) : Triangle(sides_count, name) {
	if (f != 90) {
		throw "Условия не соблюдены";
	}
}
