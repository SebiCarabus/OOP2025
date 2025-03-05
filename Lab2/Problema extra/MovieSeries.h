#pragma once
#include "Movie.h"
class MovieSeries
{
private:
	Movie* m[16];
	int count;
public:
	MovieSeries();
	void init();
	void add(Movie* a);
	void print();
	void sort();
};

