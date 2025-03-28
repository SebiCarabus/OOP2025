#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<cstring>
#include "Number.h"

///---------------Constructori--------------------
int pow_n(int n,int m)
{
	int nr = 1;
	while (m)
	{
		nr *= n;
		m--;
	}
	return nr;
}
int create_int(const char* s, int base)
{
	int nr=0,k=0,cif;
	int i, n = strlen(s);
	for (i = n - 1;i >= 0;i--)
	{
		cif = isdigit(s[i])?(int)(s[i]-'0') : (int)(s[i] - 'A' + 10);
		nr = nr + pow_n(base, k)*cif;
		k++;
	}
	return nr;
}
Number::Number(const char* value, int base)
{
	if (base < 2 || base>16 || strlen(value)>33)
		return;
	this->nb = new char[strlen(value)+1];
	this->base = base;
	if (strcmp(value, "") == 0)
	{
		this->lg = 1;
		this->nb[0] = '0';
		this->nb[1] = '\0';
	}
	else
	{
		this->lg = strlen(value);
		for (int i = 0;i < this->lg;i++)
			this->nb[i] = value[i];
		this->nb[this->lg] = '\0';
	}
	this->nr = create_int(this->nb, this->base);
}
Number::Number(int value)
{
	this->nr = value;
	this->base = 10;
	int n = value, nr = 0, i, j;
	int m = value;
	while (m)
	{
		nr++;
		m /= 10;
	}
	char* s = new char[nr+1], aux;
	nr = 0;
	while (n)
	{
		s[nr] = (char)(n % 10 + '0');
		nr++;
		n /= 10;
	}
	for (i = 0,j=nr-1;i < j;i++,j--)
	{
		aux = s[i];
		s[i] = s[j];
		s[j] = aux;
	}
	this->nb = new char[nr+1];
	this->lg = nr;
	for (i = 0;i < nr;i++)
		this->nb[i] = s[i];
	this->nb[nr] = '\0';
	delete[]s;
}
Number::Number(const Number& x)///copy constructor
{
	this->nr = x.nr;
	this->base = x.base;
	this->lg = x.lg;
	this->nb = new char[x.lg+1];
	for (int i = 0;i < this->lg;i++)
		this->nb[i] = x.nb[i];
	this->nb[this->lg] = '\0';
}
Number::Number(Number&& x) : nr(x.nr), lg(x.lg), base(x.base), nb(x.nb) ///move constructor
{
	x.nb = nullptr;
}
Number::~Number()///Destructor
{
	delete[] this->nb;
	this->nb = nullptr;
}

///-------------------Metode-----------------------
void Number::SwitchBase(int newBase)
{
	if (newBase < 2 || newBase>16)
		return;
	this->base = newBase;
	int m = this->nr, nr = 0;;
	while (m)
	{
		nr++;
		m /= this->base;
	}
	char* s = new char[nr+1];
	char c;
	int n = this->nr,r,k=0;
	while (n)
	{
		r = n % newBase;
		if (r < 10)
			c = (char)(r + '0');
		else c = (char)(r -10 + 'A');
		s[k++] = c;
		n /= newBase;
	}
	this->lg = k;
	delete[]this->nb;
	this->nb = new char[k+1];
	this->nb[k] = '\0';
	for (int i = 0;i < k;i++)
		this->nb[k-i-1] = s[i];
	delete[]s;
}
void Number::Print()
{
	for (int i = 0;i < this->lg;i++)
		printf("%c", this->nb[i]);
	printf("\n");
}
int Number::GetDigitsCount()
{
	return this->lg;
}
int Number::GetBase()
{
	return this->base;
}
int Number::GetBase10()
{
	return this->nr;
}
///-------------------Operanzi---------------------

Number operator + (const Number& a, const Number& b)
{
	Number rez = a;
	rez.nr += b.nr;
	if (a.base < b.base)
		rez.SwitchBase(b.base);
	else rez.SwitchBase(a.base);
	return rez;
}
Number operator - (const Number& a, const Number& b)
{
	Number rez = a;
	if (a.nr < b.nr)
	{
		if (a.base < b.base)
			rez.SwitchBase(b.base);
	}
	else
	{
		rez.nr -= b.nr;
		if (a.base < b.base)
			rez.SwitchBase(b.base);
		else rez.SwitchBase(a.base);
	}
	return rez;
	
}
bool Number::operator < (const Number& b)
{
	if (this->nr < b.nr)
		return true;
	return false;
}
bool Number::operator > (const Number& b)
{
	if (this->nr > b.nr)
		return true;
	return false;
}
bool Number::operator <= (const Number& b)
{
	if (this->nr <= b.nr)
		return true;
	return false;
}
bool Number::operator >= (const Number& b)
{
	if (this->nr >= b.nr)
		return true;
	return false;
}
bool Number::operator == (const Number& b)
{
	if (this->nr == b.nr)
		return true;
	return false;
}
bool Number::operator != (const Number& b)
{
	if (this->nr != b.nr)
		return true;
	return false;
}
void Number::operator += (const Number& b)
{
	this->nr += b.nr;
	if (this->base < b.base)
		this->SwitchBase(b.base);
	else
		this->SwitchBase(this->base);
}
void Number::operator -= (const Number& b)
{
	if (this->nr < b.nr)
	{
		if (this->base < b.base)
			this->SwitchBase(b.base);
	}
	else
	{
		this->nr -= b.nr;
		if (this->base < b.base)
			this->SwitchBase(b.base);
		else
			this->SwitchBase(this->base);
	}
	
}
Number& Number::operator = (const char* b)
{
	Number x(b, this->base);
	(*this) = x;
	return (*this);
}
Number& Number::operator = (const int b)
{
	Number x=b;
	x.SwitchBase(this->base);
	(*this) = x;
	return (*this);
}
Number& Number::operator = (const Number& b)
{
	///verificam daca este alt obiect
	if (this != &b)
	{
		///dialocam memoria obiectului curent ca sa facem atribuirea
		delete[]this->nb;
		this->nr = b.nr;
		this->lg = b.lg;
		///alocam memorie noua pentru atribuire
		this->nb = new char[b.lg+1];
		for (int i = 0;i < b.lg;i++)
			this->nb[i] = b.nb[i];
		this->nb[b.lg] = '\0';
	}
	return (*this);
}
Number Number::operator -- ()
{
	for (int i = 0;i < this->lg - 1;i++)
		this->nb[i] = this->nb[i + 1];
	this->nb[this->lg - 1] = '\0';
	Number x(this->nb, this->base);
	(*this) = x;
	return (*this);
	
}
Number Number::operator -- (int value)
{
	this->nb[this->lg - 1] = '\0';
	Number x(this->nb, this->base);
	(*this) = x;
	return (*this);
}
char Number::operator [](int index)
{
	if (index < 0 || index > this->lg)
		return '\0';
	return this->nb[index];
}