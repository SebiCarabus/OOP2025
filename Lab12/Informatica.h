#pragma once
#include "Materie.h"
class Informatica :
	public Materie
{
public:
	Informatica()
	{
		nume = "informatica";
		tip = "obligatorie";
		nr_credite = 5;
	}
};


