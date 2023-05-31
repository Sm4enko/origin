#include "math_power.h"

int plus(int x, int y)
{
	return x + y;
}

int minus(int x, int y)
{
	return x - y;
}int multi(int x, int y)
{
	return x * y;
}int division(int x, int y)
{
	return x / y;
}int degree(int x, int y)
{
	for (int i = 1; i < y; ++i) {
		x *= x;
	}
	return x;
}