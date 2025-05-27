#include "Student.h"

Student::Student(const string Nume, const string Nr_matricol, const string Program)
{
	nume = Nume;
	nr_matricol = Nr_matricol;
	program = Program;
}

Student::~Student() {}

void Student::adaugaNota(string materie, double nota)
{
	Materie* ce_materie;
	if (materie == "math")
		ce_materie = new Math();
	else if (materie == "optional1")
		ce_materie = new Optional1();
	else if (materie == "optional2")
		ce_materie = new Optional2();
	else if (materie == "romana")
		ce_materie = new Romana();
	else if (materie == "engleza")
		ce_materie = new Engleza();
	else if (materie == "informatica")
		ce_materie = new Informatica();
	note[ce_materie] = nota;
}

string Student::getNume()
{
	return nume;
}

string Student::getMatricola()
{
	return nr_matricol;
}

string Student::getProgram()
{
	return program;
}

void Student::arataNote()
{
	for (auto arata : note)
		cout << arata.first->getNume() << " nota: " << arata.second<<endl;
}

double Student::media()
{
	double media = 0.0;
	int nr=0;
	for (auto arata : note)
	{
		media += arata.second;
		nr++;
	}
		
	if (nr > 0)
		media /= nr;
	return media;
}
