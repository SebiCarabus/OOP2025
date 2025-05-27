#include<iostream>
#include "Catalog.h"
using namespace std;



int main() {
    Student s1("Ion Popescu", "123", "lb romana");
    s1.adaugaNota("math", 8.0);
    s1.adaugaNota("romana", 9.0);

    Student s2("Jane Doe", "456", "lb engleza");
    s2.adaugaNota("math", 9.5);
    s2.adaugaNota("informatica", 8.0);


    CatalogRO catalog(4,2);
    catalog.adaugaStudent(s1);
    catalog.adaugaStudent(s2);

    catalog.afiseazaRanking();
    return 0;
}