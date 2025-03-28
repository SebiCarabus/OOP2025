#pragma once

#include <ostream>

class Complex {
private:
    double real_data;
    double imag_data;

public:
    Complex();
    Complex(double real, double imag);

    bool is_real() const;

    double real() const;
    double imag() const;
    double abs() const;
    Complex conjugate() const;

    Complex& operator()(double real, double imag);

    friend Complex operator+(const Complex& l, const Complex& r);
    friend Complex operator+(const Complex& l, double r);
    friend Complex operator+(double l, const Complex& r);

    friend Complex operator-(const Complex& l, const Complex& r);
    friend Complex operator-(const Complex& l, double r);
    friend Complex operator-(double l, const Complex& r);

    friend Complex operator*(const Complex& l, const Complex& r);
    friend Complex operator*(const Complex& l, double r);
    friend Complex operator*(double l, const Complex& r);

    friend Complex operator-(const Complex& obj);

    friend bool operator==(const Complex& l, const Complex& r);
    friend bool operator!=(const Complex& l, const Complex& r);

    friend std::ostream& operator<<(std::ostream& out, const Complex& complex);

    friend Complex& operator ++(Complex& i, int value);
    friend Complex& operator ++(Complex& i);
    friend Complex& operator --(Complex& i, int value);
    friend Complex& operator --(Complex& i);
};


