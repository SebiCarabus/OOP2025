#pragma once
#include<string>
#include<map>
#include<iostream>
#include "Math.h"
#include "Romana.h"
#include "Engleza.h"
#include "Informatica.h"
#include "Optional1.h"
#include "Optional2.h"
using namespace std;
class Student
{
private:
	string nume;
	string nr_matricol;
	string program;
	map<Materie *, double> note;
public:
	Student(const string Nume,const string Nr_matricol, const string Program);
	~Student();
	void adaugaNota(string materie, double nota);
	string getNume();
	string getMatricola();
	string getProgram();
	void arataNote();
	double media();
};

