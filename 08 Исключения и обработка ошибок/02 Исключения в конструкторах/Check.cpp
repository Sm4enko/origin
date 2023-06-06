#include "Check.h"

class Check : public std::exception {}


bool checkTriangle::(int a, int b, int c, int d, int e, int f) {
	if (a > 0 && b > 0 && c > 0 && (a + b + c == 180)) {
		return true;
	}
	else {
		return false;
	}
}


