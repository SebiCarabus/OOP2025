#include <stdio.h>
#include <cmath>
#include "Canvas.h"
Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->m = new char* [width + 1];
	for (int i = 0;i <= width;i++)
		this->m[i] = new char[height + 1];
	int i,j;
	for (i = 0;i < width;i++)
		for (j = 0;j < height;j++)
			this->m[i][j] = ' ';
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	if (x - ray < 0 || y - ray < 0 || y + ray >= this->height || x + ray >= this->width)
		return;
	int dic;
	int djc;
	int i, j;
	for (i = 1;i <= 360;i++)
	{
		dic = x + ray*cos(i);
		djc = y + ray*sin(i);
		this->m[dic][djc] = ch;
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	if (x-ray < 0 || y-ray < 0 || y + ray >= this->height || x + ray >= this->width)
		return;
	int dic;
	int djc;
	int i, j;
	for (i = 1;i <= 360;i++)
	{
		for (j = 1;j < ray;j++)
		{
			dic = x + j * cos(i);
			djc = y + j * sin(i);
			this->m[dic][djc] = ch;
		}
		
	}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || top < 0 || right >= this->height || bottom >= this->width)
		return;
	int i, j;
	for (i = top;i <= bottom;i++)
	{
		this->m[i][right] = ch;
		this->m[i][left] = ch;
	}
	for (j = left;j <= right;j++)
	{
		this->m[top][j] = ch;
		this->m[bottom][j] = ch;
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || top < 0 || right >= this->height || bottom >= this->width)
		return;
	int i, j;
	for (i = top+1;i < bottom;i++)
	{
		for (j = left+1;j < right;j++)
			this->m[i][j] = ch;
	}
	
}
void Canvas::SetPoint(int x, int y, char ch)
{
	if (x < 0 || y < 0 || x >= this->width || y >= this->height)
		return;
	this->m[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	if (x1 < 0 || y1 < 0 || x1 >= this->width || y1 >= this->height)
		return;
	if (x2 < 0 || y2 < 0 || x2 >= this->width || y2 >= this->height)
		return;
	/// Implementarea algoritmului Bresenham
	int dx = abs(x2 - x1);
	int dy = -abs(y2 - y1);
	int cx = (x1 < x2) ? 1 : -1;///determinam in ce "directie merg x1 si y2
	int cy = (y1 < y2) ? 1 : -1;
	int eroare = dx + dy;/// cat de departe este punctul de start de linia ideala
	int eroare_dubla;
	while (1)
	{
		///daca ajungi la punctul destinatie te opresti
		if (x1 == x2 && y1 == y2)
		{
			return;
		}
		eroare_dubla = eroare * 2;
		///verificam daca punctul curent este destul de aproape de axa verticala
		///incat sa putem incerca sa il deplasam pe x1
		if (eroare_dubla>= dy)
		{
			if (x1 == x2)
			{
				break;
			}
			eroare+=dy;
			x1+=cx;
		}
		//verificam daca punctul curent este destul de aproape de axa orizontala
		///incat sa putem incerca sa il deplasam pe y1
		if (eroare_dubla <= dx)
		{
			if (y1 == y2)
			{
				break;
			}
			eroare+=dx;
			y1+=cy;
		}
		///desenam linia intre cele doua puncte excluzant capetele
		if(x1!=x2||y1!=y2)
		this->m[x1][y1] = ch;
		
	}
}
void Canvas::Print()
{
	int i, j;
	for (i = 0;i < this->width;i++)
	{
		for (j = 0;j < this->height;j++)
			printf("%c",this->m[i][j]);
		printf("\n");
	}
}
void Canvas::Clear()
{
	int i, j;
	for (i = 0;i < this->width;i++)
	{
		for (j = 0;j < this->height;j++)
			this->m[i][j]=' ';
	}
}
