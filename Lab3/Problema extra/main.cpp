#include <iostream>
#include <stdio.h>
#include "Canvas.h"
using namespace std;
int main()
{
	Canvas A(16, 16);
	A.set_pixels(3, 1, 10, '*', 2, 15,'-', 3,14,'/');
	A.print();
	getchar();
	A.clear();
	A.set_pixel(5, 5, '_');
	A.print();
	A.clear();
}