#include "Rhombus.h"

Rhombus::Rhombus(int sides_count, std::string name) : Quadrangle(sides_count, name) {
	if (a != b || a != c || a != d || e != k || f != l) {
		throw "Условия не соблюдены";
	}
}


