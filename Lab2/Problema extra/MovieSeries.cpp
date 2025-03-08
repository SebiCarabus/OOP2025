#include <stdio.h>
#include "MovieSeries.h"
#include "Movie.h"
using namespace std;
MovieSeries::MovieSeries()
{
	this->m = new Movie * [16];
	this->count = 0;
}
void MovieSeries::init()
{
	this->m = new Movie * [16];
	this->count = 0;
}
void MovieSeries::add(Movie* a)
{
	if (this->count < 16)
		this->m[this->count++] = a;	
}
void MovieSeries::print()
{
	int i;
	for (i = 0;i < this->count;i++)
	{
		printf(
			R"(
name        : %s
year        : %d
score       : %f
length      : %d
passed years: %d
)",
this->m[i]->get_name(),
this->m[i]->get_year(),
this->m[i]->get_score(),
this->m[i]->get_length(),
this->m[i]->get_passed_years());
		printf("\n");
	}
    
}
void MovieSeries::sort()
{
	int i,j;
	Movie* aux;
	for(i=0;i<this->count - 1; i++)
		for(j=i+1;j<this->count;j++)
			if (this->m[i]->get_passed_years() > this->m[j]->get_passed_years())
			{
				aux = this->m[i];
				this->m[i] = this->m[j];
				this->m[j] = aux;
			}
}

