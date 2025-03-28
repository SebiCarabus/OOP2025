#include "Complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}
Complex operator+(const Complex& l, const Complex& r)
{
    double re = l.real() + r.real();
    double i = l.imag() + r.imag();
    Complex rez(re, i);
    return rez;
}
Complex operator+(const Complex& l, double r)
{
    double re = l.real() + r;
    double i = l.imag();
    Complex rez(re, i);
    return rez;
}
Complex operator+(double l, const Complex& r)
{
    double re = r.real() + l;
    double i = r.imag();
    Complex rez(re, i);
    return rez;
}

Complex operator-(const Complex& l, const Complex& r)
{
    double re = l.real() - r.real();
    double i = l.imag() - r.imag();
    Complex rez(re, i);
    return rez;
}
Complex operator-(const Complex& l, double r)
{
    double re = l.real() - r;
    double i = l.imag();
    Complex rez(re, i);
    return rez;
}
Complex operator-(double l, const Complex& r)
{
    double re = r.real() - l;
    double i = r.imag();
    Complex rez(re, i);
    return rez;
}

Complex operator-(const Complex& obj)
{
    double re = -1 * obj.real();
    double i = -1 * obj.imag();
    Complex rez(re, i);
    return rez;
}

Complex operator*(const Complex& l, const Complex& r)
{
    double re = l.real() * r.real() - l.imag() * r.imag();
    double i = l.real() * r.imag() + l.imag() * r.real();
    Complex rez(re, i);
    return rez;
}
Complex operator*(const Complex& l, double r)
{
    double re = l.real() * r;
    double i = l.imag() * r;
    Complex rez(re, i);
    return rez;
}
Complex operator*(double l, const Complex& r)
{
    double re = r.real() * l;
    double i = r.imag() * l;
    Complex rez(re, i);
    return rez;
}

bool operator==(const Complex& l, const Complex& r)
{
    if (l.real() == r.real() && l.imag() == r.imag())
        return true;   
    return false;
}
bool operator!=(const Complex& l, const Complex& r)
{  
    if (l.real() == r.real() && l.imag() == r.imag())
        return false;
    return true;
}
std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    int ok = 0;
    if (complex.real() != 0)
    {
        ok = 1;
        out << complex.real();
    }
    else if (complex.imag() == 0)
        out << 0 ;
    if (complex.imag() > 0)
    {
        if (ok == 1)
            out << " + " <<complex.imag() << "i";
        else out << complex.imag() << "i";
    }
    else
    {
        if (complex.imag() < 0)
        {
            if (ok == 1)
                out << " - " << -1 * complex.imag() << "i";
            else out << complex.imag() << "i";
        }
    }
    return out;
}

Complex& operator ++(Complex& i, int value)
{
    Complex temp(i.real(), i.imag());
    i.real_data++;
    return temp;
}
Complex& operator ++(Complex& i)
{
    i.real_data++;
    return i;
}
Complex& operator --(Complex& i, int value)
{
    Complex temp(i.real(), i.imag());
    i.real_data--;
    return temp;
}
Complex& operator --(Complex& i)
{
    i.real_data--;
    return i;
}

Complex& Complex::operator()(double real, double imag)
{
    this->real_data=real;
    this->imag_data = imag;
    return(*this);
}
