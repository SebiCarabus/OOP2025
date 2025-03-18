#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
	srand(time(NULL));
	bool ascendent;
	const char s[100] = "10,15,4";
	Sort A(s);
	cout<<A.GetElementFromIndex(1)<<" "<<A.GetElementsCount()<<endl;
	A.Print();
	
	cout << endl;

	Sort B(5, 1, 8);
	B.Print();
	B.BubbleSort();
	B.Print();
	cout << endl;

	Sort C(5, 6, 2, 5, 10, 7);
	C.Print();
	C.QuickSort();
	C.Print();
	cout << endl;

	int *v=new int[10];
	v[0] = 43;
	v[1] = 32;
	v[2] = 54;
	v[3] = 2;
	v[4] = 3;
	int n = 5;
	Sort D(v, n);
	D.Print();
	D.InsertSort();
	D.Print();
	cout << endl;

	Sort E{ 45, 3,8 ,6 ,10, 19 };
	E.Print();
	E.QuickSort();
	E.Print();
	cout << endl;

	return 0;
}