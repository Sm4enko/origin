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
}

class ComplexNumber
{
    int re_, im_;
public:
    ComplexNumber(int re, int im) { re_ = re; im_ = im; }
    ComplexNumber operator+(ComplexNumber other)
    {
        return ComplexNumber(re_ + other.re_, (im_ + other.im_) / 2);
    }

    ComplexNumber operator-(ComplexNumber other)
    {
        return ComplexNumber(re_ - other.re_, other.im_);
    }

    ComplexNumber operator*(ComplexNumber other)
    {
        return ComplexNumber(re_ * other.re_, (im_ * other.im_));
    }

    ComplexNumber operator/(ComplexNumber other)
    {
        return ComplexNumber(re_ * other.im_, (im_ * other.re_));
    }

    ComplexNumber& operator++() { re_++; im_++; return *this; }
    ComplexNumber operator++(int)
    {
        ComplexNumber temp = *this;
        ++(*this);
        return temp;
    }


    void Print() {
        reduceFraction(re_, im_);
        std::cout << re_ << (im_ < 0 ? "" : "+") << im_ << "i\n";
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

    ComplexNumber c1(a, b), c2(x, y);
    ComplexNumber sum_c_c = c1 + c2;
    ComplexNumber min_c_c = c1 - c2;
    ComplexNumber divide_c_c = c1 / c2;
    ComplexNumber multi_c_c = c1 * c2;
    ComplexNumber pre_multi_c_c = ++c1 * c2;

    sum_c_c.Print();
    min_c_c.Print();
    multi_c_c.Print();
    divide_c_c.Print();
    pre_multi_c_c.Print();

}