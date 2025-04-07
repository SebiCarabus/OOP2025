#pragma once
#include "Car.h"
class Volvo : public Car
{
public:
	Volvo(const char* nc, unsigned int f1, unsigned int f2, unsigned int s1, unsigned int s2, unsigned int s3);
	Volvo();
	char* get_name()const override;
	unsigned int get_f_consumtion()const override;
	unsigned int get_f_capacity()const override;
	unsigned int speed_i(int index)const override;

};

