#include "Rectangle.h"

Rectangle::Rectangle(int sides_count, std::string name) : Quadrangle(sides_count, name) {
	if (a != b || c != d || e != 90 || f != 90 || k != 90 || l != 90) {
		throw "Условия не соблюдены";
	}
}





