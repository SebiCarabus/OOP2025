#pragma once
#include "Student.h"
class Catalog
{
protected:
	Student** studenti;
	unsigned int n, m, nr;
public:
	void adaugaStudent(Student s)
	{
		if(nr<n)
			studenti[nr++]=new Student(s);
	}
	void obtinereNote(string s)
	{
		for(int i=0;i<nr;i++)
			if (studenti[i]->getNume() == s)
			{
				cout << s << endl;
				studenti[i]->arataNote();
				return;
			}
		cout << "Studentul " << s << " nu este inregistrat in catalog!";
	}
	void afiseazaRanking()
	{
		auto f=[](double a, double b)->bool { return a > b; };
		Student **rank_studenti = new Student * [n],*aux;
		for (int i = 0;i < nr;i++)
			rank_studenti[i] = new Student(*studenti[i]);
		for (int i = 0;i < nr-1;i++)
			for (int j = i+1 ;j < nr; j++)
				if (f(rank_studenti[i]->media(), rank_studenti[j]->media()) == false)
				{
					aux = rank_studenti[i];
					rank_studenti[i] = rank_studenti[j];
					rank_studenti[j] = aux;
				}
		for (int i = 0;i < nr;i++)
			cout << rank_studenti[i]->getNume() << " " << rank_studenti[i]->media()<<endl;

		for (int i = 0;i < nr;i++)
			delete rank_studenti[i];
		delete[]rank_studenti;
	}
};

class CatalogRO: public Catalog
{
public:
	CatalogRO(const unsigned int n, const unsigned int m)
	{
		this->n = n;
		this->m = m;
		nr = 0;
		studenti = new Student*[n];
	}
	~CatalogRO()
	{
		for (int i = 0;i < this->nr;i++)
			delete this->studenti[i];
		delete[]studenti;
	}
};