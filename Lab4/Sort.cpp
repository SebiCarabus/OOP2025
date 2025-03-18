#include <cstring>
#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <initializer_list>
#include <stdarg.h>
#include <cstdlib>
#include "Sort.h"

//-------------Constructori------------------------

Sort::Sort(int n, int minim, int maxim)
{
	if (minim > maxim)
	{
		int aux = maxim;
		maxim = minim;
		minim = aux;
	}
	this->nrElem = n;
	this->lista = new int[this->nrElem + 1];
	for (int i = 0;i < this->nrElem;i++)
	{
		this->lista[i] = (minim+rand())%maxim;
	}
}
Sort::Sort(std::initializer_list<int>l)
{
	int i;
	this->nrElem = l.size();
	this->lista = new int[this->nrElem];
	int n=0;
	for (const int *i = l.begin() ;i != l.end();i++, n++)
		this->lista[n] = (*i);
}
Sort::Sort(int *v, int n)
{
	this->nrElem = n;
	this->lista = new int[n + 1];
	for (int i = 0;i < n;i++)
	{
		this->lista[i] = v[i];
	}
}
Sort::Sort(int n, ...)
{
	va_list args;
	va_start(args,n);
	this->nrElem = n;
	this->lista = new int[n];
	int i = 0;
	while (n)
	{
		this->lista[i] = va_arg(args, int);
		i++;
		n--;
	}
}
Sort::Sort(const char s[100])
{
	int n = 0,lg=strlen(s);
	int i = 0;
	int* v = new int[100];
	int nr_curent = 0;
	for(i=0;i<=lg;i++)
	{
		if (s[i] != ','&& s[i]!='\0')
			nr_curent = nr_curent * 10 + (int)(s[i] - '0');
		else
		{
			v[n++] = nr_curent;
			nr_curent = 0;
		}
	}
	int x;
	this->nrElem = n;
	this->lista = new int[n];
	for (i = 0;i < n;i++)
		this->lista[i] = v[i];
}

//--------Elemente-------------
 
int Sort::GetElementFromIndex(int index)
{
	return this->lista[index];
}

int Sort::GetElementsCount()
{
	return this->nrElem;
}

void Sort::Print()
{
	for (int i = 0;i < this->nrElem;i++)
		printf("%d ", this->lista[i]);
	printf("\n");
}
//-----------Destructor-----------

Sort::~Sort()
{
	delete [] this->lista;
	this->nrElem = 0;
}
//---------Sortari---------------

void Sort::InsertSort(bool ascendent)
{
	int i, j,temp;
	for (i = 1;i < this->nrElem;i++)
	{
		temp = this->lista[i];
		j = i - 1;
		while (j>=0 && this->lista[j] > temp)
		{
			this->lista[j + 1] = this->lista[j];
			j--;
		}
		if (j + 1 != i)
			this->lista[j + 1] = temp;
	}
	ascendent = true;
}

void Sort::BubbleSort(bool ascendent)
{
	int n = this->nrElem, n1;
	int ultim = n-2;
	int i,aux;
	while (ultim > 0)
	{
		n1=ultim;
		ultim = 0;
		for (i = 0;i <= n1;i++)
			if (this->lista[i] > this->lista[i + 1])
			{
				aux = this->lista[i+1];
				this->lista[i + 1] = this->lista[i];
				this->lista[i] = aux;
				ultim = i;
			}
	}
	ascendent = true;
}
void quickSort(int *v, int st, int dr)
{
	if (st < dr)
	{
		int aux;
		///partitionare dupa pivot
		int pivot = v[st];
		int i = st + 1;
		int j = dr;
		while (i <= j)
		{
			if (v[i] <= pivot)
				i++;
			if (pivot <= v[j])
				j--;
			if (i < j && v[i] > pivot && pivot > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				i++;
				j--;
			}
		}
		aux = v[st];
		v[st] = v[i - 1];
		v[i - 1] = aux;
		quickSort(v, st, i - 2);
		quickSort(v, i, dr);
	}
}
void Sort::QuickSort(bool ascendent)
{
	quickSort(this->lista, 0, this->nrElem - 1);
	ascendent=true;
}


