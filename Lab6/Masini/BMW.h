#pragma once
#include "Car.h"
class BMW : public Car
{
public:
	BMW(const char* nc, unsigned int f1, unsigned int f2, unsigned int s1, unsigned int s2, unsigned int s3);
	BMW();
	char* get_name()const override;
	unsigned int get_f_consumtion()const override;
	unsigned int get_f_capacity()const override;
	unsigned int speed_i(int index)const override;
};

