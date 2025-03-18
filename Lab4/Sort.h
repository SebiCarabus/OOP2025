#pragma once
class Sort
{
private:
    int *lista, nrElem;
public:
    Sort(int n, int minim, int maxim);
    Sort(std::initializer_list<int>l);
    Sort(int *v, int n);
    Sort(int n, ...);
    Sort(const char s[100]);

    ~Sort();

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};

