#include "Movie.h"
#include <cstring>
Movie::Movie()
{
	this->name = nullptr;
	this->length = 0;
	this->score = 0.0;
	this->year = 0;
}
const char* Movie::get_name()
{
	return this->name;
}
void Movie::set_name(const char* s)
{
	int lgs = strlen(s);
	this->name = new char[lgs + 1];
	memcpy(this->name, s, lgs);
	this->name[lgs] = '\0';
}
int Movie::get_year()
{
	return this->year;
}
void Movie::set_year(int x)
{
	if(x>0)
	this->year = x;
}
int Movie::get_length()
{
	return this->length;
}
void Movie::set_length(int x)
{
	if (x>0)
	this->length = x;
}
double Movie::get_score()
{
	return this->score;
}
void Movie::set_score(double x)
{
	if (x > 0)
		this->score = x;
}
int Movie::get_passed_years()
{
	return 2025 - this->year;
}
