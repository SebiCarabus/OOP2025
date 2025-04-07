#include <iostream>

using namespace std;

float operator""_Kelvin(long double x) { return static_cast<float>(x - 273.5); }
float operator""_Fahrenheit(long double x) { return static_cast<float>((x - 32) * 5 / 9); }

int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;
    cout << a << endl << b;
    return 0;
}