#include <cstring>
#include "Student.h"
Student::Student()
{
	this->name = nullptr;
	this->math = 0;
	this->histo = 0;
	this->eng = 0;
}
const char* Student::get_name()
{
	return this->name;
}
void Student::set_name(const char *s)
{
	int lgs = strlen(s);
	this->name = new char[lgs + 1];
	memcpy(this->name, s, lgs);
	this->name[lgs] = '\0';
}
float Student::get_math()
{
	return this->math;
}
void Student::set_math(float x)
{
	if(x>=0&&x<=10)
	this->math = x;
}
float Student::get_eng()
{
	return this->eng;
}
void Student::set_eng(float x)
{
	if (x >= 0 && x <= 10)
	this->eng = x;
}
float Student::get_histo()
{
	return this->histo;
}
void Student::set_histo(float x)
{
	if (x >= 0 && x <= 10)
	this->histo = x;
}
float Student::get_avg()
{
	return (this->math+this->eng+this->histo)/3;
}