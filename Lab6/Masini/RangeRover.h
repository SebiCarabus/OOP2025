#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
	RangeRover(const char* nc, unsigned int f1, unsigned int f2, unsigned int s1, unsigned int s2, unsigned int s3);
	RangeRover();
	char* get_name()const override;
	unsigned int get_f_consumtion()const override;
	unsigned int get_f_capacity()const override;
	unsigned int speed_i(int index)const override;
};