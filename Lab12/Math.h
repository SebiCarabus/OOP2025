#pragma once
#include "Materie.h"
class Math :
	public Materie
{
public:
	Math()
	{
		nume = "math";
		tip = "obligatorie";
		nr_credite = 5;
	}
};

