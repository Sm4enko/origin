#include <iostream>
#include <cmath>

class Fraction
{
	int numerator_, denominator_;
public:
	Fraction(int numerator, int denominator) { numerator_ = numerator; denominator_ = denominator; }
	double Abs() { return std::sqrt(numerator_ * numerator_ + denominator_ * denominator_); }
	bool operator==(Fraction other) { return Abs() == other.Abs(); }
	bool operator!=(Fraction other) { return !(*this == other); }
	bool operator<(Fraction other) { return other > *this; }
	bool operator>(Fraction other) { return Abs() > other.Abs(); }
	bool operator<=(Fraction other) { return !(*this > other); }
	bool operator>=(Fraction other) { return !(*this < other); }

};
int main(int argc, char** argv)
{
	Fraction f1(1, 1), f2(4, 2);
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n'; // here
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
}