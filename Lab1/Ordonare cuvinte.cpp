#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void pune_ordonat(int &k,char sol[200][20], char myString[200])
{
	int c, nrc = 0, n = strlen(myString);
	myString[n] = '\0';
	k++;
	for (int i = 0;i <= n;i++)
		sol[k][i] = myString[i];
	int j = k;
	while (j > 1 && strlen(sol[j-1])<strlen(sol[j]))
	{
		swap(sol[j - 1], sol[j]);
		j--;
	}
	while (j > 1 && strcmp(sol[j], sol[j - 1]) > 0)
	{
		swap(sol[j - 1], sol[j]);
		j--;
	}
}
int main()
{
	int numarCuvinte,k=0;
	scanf_s("%d", &numarCuvinte, 4);
	printf("Introduceti o propozitie: ");
	char cuvant[20],sol[200][20];
	//scanf("%19s", cuvant);
	int counter = 0;
	while (scanf_s("%19s", cuvant, 19))
	{
		//if (strcmp(cuvant, "\n\n") == 0)
		//	break;
		//printf("Cuvantul citit este: %s\n", cuvant);
		if (counter < 200)
		{
			pune_ordonat(k, sol, cuvant);
		}
		counter += 1;
		if (counter >= numarCuvinte)
			break;
	}
	for (int i = 1;i <= k;i++)
		printf("%s\n", sol[i]);
	return 0;
}