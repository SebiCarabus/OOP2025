#include "Seat.h"
Seat::Seat(const char* nc, unsigned int f1, unsigned int f2, unsigned int s1, unsigned int s2, unsigned int s3)
{
	this->f_con = f1;
	this->f_cap = f2;
	this->name = new char[strlen(nc) + 1];
	int i;
	for (i = 0;i < strlen(nc);i++)
		this->name[i] = nc[i];
	this->name[i] = '\0';
	this->speed = new unsigned int[3];
	this->speed[0] = s1;
	this->speed[1] = s2;
	this->speed[2] = s3;
}
Seat::Seat() : Seat((const char*)"Seat", 450, 500, 180, 70, 20) {}
char* Seat::get_name()const
{
	return this->name;
}
unsigned int Seat::get_f_consumtion()const
{
	return this->f_con;
}
unsigned int Seat::get_f_capacity()const
{
	return this->f_cap;
}
unsigned int Seat::speed_i(int index)const
{
	return this->speed[index];
}
