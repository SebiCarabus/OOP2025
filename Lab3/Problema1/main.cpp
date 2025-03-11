#include <iostream>
#include "Math.h";
using namespace std;
int main()
{
	int a = 10, b = 2, c = 13;
	double x = 11.2, y = 23.5, z = 0.3;
	cout << Math::Add(a, b) << endl;
	cout << Math::Add(a, b,c) << endl;
	cout << Math::Add(x, y) << endl;
	cout << Math::Add(x, y,z) << endl;
	cout << Math::Add(4, 1, 2, 3, 4)<<endl;
	cout << Math::Add('a','b') << endl;
	cout << Math::Mul(a, b) << endl;
	cout << Math::Mul(a, b,c) << endl;
	cout << Math::Mul(x, y) << endl;
	cout << Math::Mul(x,y,z) << endl;
	return 0;
}