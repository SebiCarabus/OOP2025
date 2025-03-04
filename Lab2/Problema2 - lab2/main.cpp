#include <iostream>
#include "Student.h"
#include "GlobalFunctions.h"
using namespace std;
int main()
{
	Student a, b;
	
	a.set_name((const char*)"Viu Mihai");
	a.set_eng(5.6);
	cout << "Nota la engleza a elevului "<<a.get_name()<<" este "<< a.get_eng()<<endl;
	a.set_math(9.1);
	cout << "Nota la matematica a elevului " << a.get_name() << " este " << a.get_math()<<endl;
	a.set_histo(2.3);
	cout << "Nota la istorie a elevului " << a.get_name() << " este " << a.get_histo()<<endl;
	cout << "Media elevului " << a.get_name() << " este " << a.get_avg()<<endl;
	
	cout << endl;

	b.set_name((const char*)"Matei Nicolau");
	b.set_eng(7.6);
	cout << "Nota la engleza a elevului " << b.get_name() << " este " << b.get_eng()<<endl;
	b.set_math(8.1);
	cout << "Nota la matematica a elevului " << b.get_name() << " este " << b.get_math()<<endl;
	b.set_histo(2.3);
	cout << "Nota la istorie a elevului " << b.get_name() << " este " << b.get_histo()<<endl;
	cout << "Media elevului " << b.get_name() << " este " << b.get_avg()<<endl;
	cout << endl;

	cout <<"Rezultat comparare dupa nume: "<< comp_name(&a, &b) << endl;
	cout <<"Rezultat comparare dupa media la mate: "<< comp_math(&a, &b) << endl;
	cout <<"Rezultat comparare dupa media la engleza: "<< comp_eng(&a, &b) << endl;
	cout <<"Rezultat comparare dupa media la istorie: "<< comp_histo(&a, &b) << endl;
	cout <<"Rezultat comparare dupa media generala: "<< comp_avg(&a, &b) << endl;

	return 0;
}