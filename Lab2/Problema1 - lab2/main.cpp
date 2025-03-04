#include <iostream>
#include "NumberList.h"
using namespace std;
int main()
{
	NumberList v;
	v.Init();
	v.Add(3);
	v.Add(1);
	v.Add(4);
	v.Add(2);

	v.Print();

	v.Sort();
	v.Print();
	return 0;
}