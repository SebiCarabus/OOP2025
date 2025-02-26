#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{	
	int sc = 0;
	FILE* fp;
	if (fopen_s(&fp, "in.txt", "r") != 0)
	{
		printf("Eroare. Nu am putut deschide fisierul\n");
	}
	else {
		char myString[200];
		while (fgets(myString, 200, fp))
		{
			int c,nrc=0,n = strlen(myString) - 1;
			myString[n] = '\0';
			for (int i = 0;i < n;i++)
			{
				c = myString[i] - '0';
				nrc = nrc * 10+c;
			}
			printf("%d ", nrc);
			sc += nrc;
		}
	}
	fclose(fp);
	printf("\n%d", sc);
	return 0;
}