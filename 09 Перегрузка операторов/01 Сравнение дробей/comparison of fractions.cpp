#include <iostream>
#include <cmath>

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void reduceFraction(int& numerator, int& denominator) {
    int gcd = findGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

class Fraction
{
    int numerator_, denominator_;
public:
    Fraction(int numerator, int denominator) { numerator_ = numerator; denominator_ = denominator; }
    double Abs() { return std::sqrt(numerator_ * numerator_ + denominator_ * denominator_); }
    bool operator==(Fraction other) { return numerator_ == other.numerator_ && denominator_ == other.denominator_; }
    bool operator!=(Fraction other) { return !(*this == other); }
    bool operator<(Fraction other) {
        if (numerator_ == other.numerator_ && denominator_ == other.denominator_)
            return false;
        return numerator_ * other.denominator_ < other.numerator_* denominator_;
    }
    bool operator>(Fraction other) { return other < *this; }
    bool operator<=(Fraction other) { return !(*this > other); }
    bool operator>=(Fraction other) { return !(*this < other); }
};

int main(int argc, char** argv)
{
    int a = 4;
    int b = 3;
    int c = 8;
    int d = 6;
    reduceFraction(a, b);
    reduceFraction(c, d);
    Fraction f1(a, b), f2(c, d);
    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
}
