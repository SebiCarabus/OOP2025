#include "Student.h"
#include "GlobalFunctions.h"
#include <cstring>

int comp_name(Student a, Student b)
{
	char* s1 = a.get_name(), * s2 = b.get_name();
	return strcmp(s1, s2);
}
int comp_math(Student a, Student b)
{
	int n1=a.get_math(), n2 = b.get_math();
	if (n1 < n2)return -1;
	if (n1 > n2)return 1;
	return 0;
}
int comp_eng(Student a, Student b)
{
	int n1 = a.get_eng(), n2 = b.get_eng();
	if (n1 < n2)return -1;
	if (n1 > n2)return 1;
	return 0;
}
int comp_histo(Student a, Student b)
{
	int n1 = a.get_histo(), n2 = b.get_histo();
	if (n1 < n2)return -1;
	if (n1 > n2)return 1;
	return 0;
}
int comp_avg(Student a, Student b)
{
	int n1 = a.get_avg(), n2 = b.get_avg();
	if (n1 < n2)return -1;
	if (n1 > n2)return 1;
	return 0;
}