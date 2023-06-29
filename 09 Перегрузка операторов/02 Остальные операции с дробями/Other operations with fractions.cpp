#include <iostream>
#include <cmath>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void reduceFraction(int& numerator, int& denominator) {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

class Fraction
{
    int numerator_, denominator_;
public:
    Fraction(int numerator, int denominator) { numerator_ = numerator; denominator_ = denominator; }
    Fraction operator+(Fraction other)
    {
        return Fraction(numerator_ * other.denominator_ + other.numerator_ * denominator_, denominator_ * other.denominator_);
    }

    Fraction operator-(Fraction other)
    {
        return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_);
    }

    Fraction operator*(Fraction other)
    {
        return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator/(Fraction other)
    {
        return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
    }

    Fraction& operator++() { numerator_ += denominator_; return *this; }
    Fraction operator++(int)
    {
        Fraction temp = *this;
        numerator_ += denominator_;
        return temp;
    }

    Fraction& operator--() { numerator_ -= denominator_; return *this; }
    Fraction operator--(int)
    {
        Fraction temp = *this;
        numerator_ -= denominator_;
        return temp;
    }

    void Print() {
        reduceFraction(numerator_, denominator_);
        std::cout << numerator_ << (denominator_ < 0 ? "" : "/") << denominator_ << "\n";
    }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    int a, b, x, y, temp;
    int count = 0;
    std::cout << "¬ведите числитель дроби 1: ";
    std::cin >> a;
    std::cout << "¬ведите знаменатель дроби 1: ";
    std::cin >> b;
    std::cout << "¬ведите числитель дроби 2: ";
    std::cin >> x;
    std::cout << "¬ведите знаменатель дроби 2: ";
    std::cin >> y;

    if (b != y) {
        temp = b;
        a *= y;
        b *= y;
        x *= temp;
        y *= temp;
    }

    Fraction f1(a, b), f2(x, y);
    Fraction sum_f_f = f1 + f2;
    Fraction min_f_f = f1 - f2;
    Fraction divide_f_f = f1 / f2;
    Fraction multi_f_f = f1 * f2;
    Fraction pre_multi_f_f = ++f1 * f2;

    sum_f_f.Print();
    min_f_f.Print();
    multi_f_f.Print();
    divide_f_f.Print();
    pre_multi_f_f.Print();

    return 0;
}
