#pragma once
#include<string>
using namespace std;
class Materie
{
protected:
	string tip;
	string nume;
	unsigned int nr_credite;
public:
	virtual string getNume() { return nume; }
	virtual string getTip() { return tip; }
	virtual unsigned int getCredite() { return nr_credite;}
};

