#pragma once
#include "Movie.h"
class MovieSeries
{
private:
	Movie** m;
	int count;
public:
	MovieSeries();
	void init();
	void add(Movie* a);
	void print();
	void sort();
};

