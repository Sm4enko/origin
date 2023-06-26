#include "Parallelogram.h"

Parallelogram::Parallelogram(int sides_count, std::string name) : Quadrangle(sides_count, name) {
	if (a != b || c != d || e != k || f != l) {
		throw "Условия не соблюдены";
	}
}




