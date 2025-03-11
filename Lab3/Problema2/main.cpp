#include <iostream>
#include <stdio.h>
#include "Canvas.h"
using namespace std;
int main()
{
	Canvas c(16, 16);
	c.SetPoint(5, 5, '*');
	c.SetPoint(8, 9, '*');
	c.DrawLine(5, 5, 8, 9, '-');
	c.Print();
	c.Clear();
	getchar();
	c.SetPoint(5, 5, '*');
	c.SetPoint(5, 9, '*');
	c.DrawLine(5, 5, 5, 9, '-');
	c.Print();
	c.Clear();
	getchar();
	c.SetPoint(5, 5, '*');
	c.SetPoint(9, 5, '*');
	c.DrawLine(5, 5, 9, 5, '-');
	c.Print();
	c.Clear();
	getchar();
	c.DrawCircle(5, 5, 5, '*');
	c.Print();
	getchar();
	c.FillCircle(5, 5, 5, '+');
	c.Print();
	c.Clear();
	getchar();
	c.DrawRect(5, 5, 8, 9, '-');
	c.Print();
	getchar();
	c.FillRect(5, 5, 8, 9, '*');
	c.Print();
	c.Clear();
	getchar();
	return 0;
}