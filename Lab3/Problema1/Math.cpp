#include <cstring>
#include <stdio.h>
#include <cstdarg>
#include "Math.h"
int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b, double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}
int Math::Add(int count, ...)
{
	int i,rez = 0,element;
	int* p = &count;
	p+=2;
	for (i = 0;i < count;i++)
	{
		rez += (*p);
		p+=2;
	}
	return rez;
}
char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
		return nullptr;
	int n = strlen(a), m = strlen(b);
	int z = 0,lg = n > m ? n : m;
	int i = n - 1, j= m - 1;
	int c1, c2,t=0;
	char* rez = new char[lg + 2];
	while (i >= 0 && j >= 0)
	{
		c1 = a[i--] - '0';
		c2 = b[j--] - '0';
		rez[z++] = (char)((c1 + c2 + t) % 10 + '0');
		t = (c1 + c2 + t) / 10;
	}
	while (i >= 0)
	{
		c1 = a[i--] - '0';
		rez[z++] = (char)((c1 + t) % 10 + '0');
		t = (c1 + t) / 10;
	}
	while (j >= 0)
	{
		c2 = b[j--] - '0';
		rez[z++] =(char)((c2 + t) % 10+'0');
		t = (c2 + t) / 10;
	}
	rez[z] = '\0';
	char aux;
	for (i = 0,j=z-1;i < j;i++,j--)
	{
		aux = rez[i];
		rez[i] = rez[j];
		rez[j] = aux;
	}
	return rez;
}
