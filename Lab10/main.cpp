#include "Array.h"

int main()
{
    Array<int> v(10);
    Array<int> c(10);
    v += 9;
    c += 8;
    c += 5;
    v += 10;
    v.Insert(1, c);
    for (auto elem = v.GetBeginIterator();elem != v.GetEndIterator(); elem++)
        cout << *elem << " ";
    cout << endl;
    v.Sort();
    v.Delete(2);
    v[0] = 20;
    for (auto elem = v.GetBeginIterator();elem != v.GetEndIterator(); elem++)
        cout << *elem << " ";
    cout << endl;
    cout << v.Find(8) << endl;
    cout << v.BinarySearch(10) << endl;
    return 0;
}

