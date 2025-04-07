#pragma once
#include<cstring>

class Car
{
protected:
	char* name;
	unsigned int f_con, f_cap;
	unsigned int* speed;
public:
	virtual char* get_name() const = 0;
	virtual unsigned int get_f_consumtion() const = 0;
	virtual unsigned int get_f_capacity() const = 0;
	virtual unsigned int speed_i(int index) const = 0;
};
