#include <stdio.h>
#include "NumberList.h"

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	this->numbers[this->count++] = x;
	if (this->count <= 10)
		return true;
	return false;
}

void NumberList::Sort()
{
	int i,j,aux, n = this->count;
	for (i = 0;i < n - 1;i++)
		for (j = i + 1;j < n;j++)
			if (this->numbers[i] > this->numbers[j])
			{
				aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}		
}
void NumberList::Print()
{
	int i, j, aux, n = this->count;
	for (i = 0;i < n;i++)
		printf("%d ",this->numbers[i]);
	printf("\n");
}