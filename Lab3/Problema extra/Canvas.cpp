#include <stdio.h>
#include "Canvas.h"
void Canvas::clear()
{
	int i, j;
	for (i = 0;i < this->l;i++)
		for (j = 0;j < this->c;j++)
			this->m[i][j] = ' ';
}
void Canvas::print()const
{
	int i, j;
	for (i = 0;i < this->l;i++)
	{
		for (j = 0;j < this->c;j++)
			printf("%c",this->m[i][j]);
		printf("\n");
	}
		
}
Canvas::Canvas(int lines, int colums)
{
	this->l = lines;
	this->c = colums;
	this->m = new char* [lines + 1];
	for (int i = 0;i < lines;i++)
		this->m[i] = new char [colums + 1];
	this->clear();
}
void Canvas::set_pixel(int x, int y, char value)
{
	if (x < 0 || y < 0 || x >= this->l || y >= this->c)
		return;
	this->m[x][y] = value;
}
void Canvas::set_pixels(int count, ...)
{
	int i, ls, cs;
	int* p =&count;
	p += 2;
	for (i = 0;i < count;i++)
	{
		ls = *p;
		cs = *(p + 2);
		if (!(ls< 0 || cs< 0 || ls>= this->l || cs>= this->c))
		this->m[ls][cs] = (char)*(p + 4);
		p += 6;
	}
}