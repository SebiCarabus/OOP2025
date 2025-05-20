#pragma once
#include<iostream>
#include <exception>
using namespace std;

class out_of_rng : public exception
{
    virtual const char* what() const throw()
    {
        return "Nu te afli in aria de acoperire a array-ului!";
    }
};
class out_of_spc : public exception
{
    virtual const char* what() const throw()
    {
        return "Nu ai destul spatiu!";
    }
};
class nu_sortat : public exception
{
    virtual const char* what() const throw()
    {
        return "Array-ul nu este sortat!";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
    T** Val;
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
    ArrayIterator()
    {
        this->Val = nullptr;
        this->Current = 0;
    }
    ArrayIterator(T** Lista, int index)
    {
        this->Val = Lista;
        this->Current = index;
    }
    ArrayIterator<T>& operator ++ ()
    {
        this->Current++;
        this->Val++;
        return *this;
    }
    ArrayIterator<T>& operator -- ()
    {
        this->Current--;
        this->Val--;
        return *this;
    }
    ArrayIterator<T>& operator ++ (int val)
    {
        ArrayIterator<T> temp(this->Val, this->Current);
        this->Current++;
        this->Val++;
        return temp;
    }
    ArrayIterator<T>& operator -- (int val)
    {
        ArrayIterator<T> temp(this->Val, this->Current);
        this->Current--;
        this->Val--;
        return temp;
    }
    bool operator== (const ArrayIterator<T>& o)
    {
        if (*this->Val == *o.Val)
            return true;
        return false;
    }
    bool operator!=(const ArrayIterator<T>& o)
    {
        if (*this->Val == *o.Val)
            return false;
        return true;
    }
    T& operator*()
    {
        return **this->Val;
    }
    T* GetElement()
    {
        return *this->Val;
    }
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() // Lista nu e alocata, Capacity si Size = 0
    {
        this->Size = 0;
        this->Capacity = 0;
        this->List = nullptr;
    }
    ~Array() // destructor
    {
        if (this->List != nullptr)
        {
            for (int i = 0;i < this->Size;i++)
                delete this->List[i];
            delete[]this->List;
        }
    }
    Array(int capacity) // Lista e alocata cu 'capacity' elemente
    {
        this->Size = 0;
        this->Capacity = capacity;
        this->List = new T * [capacity];
        for (int i = 0;i < this->Capacity;i++)
            this->List[i] = nullptr;
    }
    Array(const Array<T>& otherArray) // constructor de copiere
    {
        if (this->List != nullptr)
        {
            for (int i = 0;i < this->Size;i++)
                delete this->List[i];
            delete[]this->List;
        }
        this->Size = otherArray.Size;
        this->Capacity = otherArray.Capacity;
        this->List = new  T * [this->Capacity];
        for (int i = 0;i < this->Size;i++)
            this->List[i] = new T(*otherArray.List[i]);
    }

    T& operator[] (int index) // arunca exceptie daca index este out of range
    {
        out_of_rng r;
        try
        {
            if (index < 0 || index >= this->Size)
                throw r;
            return *this->List[index];
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }

    }
    const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
    {
        out_of_spc s;
        try
        {
            if (this->Size >= this->Capacity)
                throw s;
            this->List[this->Size] = new T(newElem);
            this->Size++;
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }
        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        out_of_rng r;
        out_of_spc s;
        try
        {
            if (this->Size >= this->Capacity)
                throw s;
            if (index < 0 || index > this->Size)
                throw r;
            for (int i = this->size;i > index;i--)
                this->List[i] = this->List[i - 1];
            this->List[index] = new T(newElem);
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        out_of_rng r;
        out_of_spc s;
        try
        {
            if (this->Size + otherArray.Size - 1 >= this->Capacity)
                throw s;
            if (index < 0 || index > this->Size)
                throw r;
            for (int j = 0;j < otherArray.Size;j++)
                for (int i = this->Capacity - 1;i > index;i--)
                    this->List[i] = this->List[i - 1];
            for (int j = 0;j < otherArray.Size;j++)
                this->List[index + j] = new T(*otherArray.List[j]);
            this->Size += otherArray.Size;
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }
        return *this;
    }
    const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        out_of_rng r;
        try
        {
            if (index < 0 || index >= this->Size)
                throw r;
            delete this->List[index];
            for (int i = index;i < this->Size - 1;i++)
                this->List[i] = this->List[i + 1];
            this->Size--;
            this->List[Size] = nullptr;

        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }
        return *this;
    }

    bool operator==(const Array<T>& otherArray)
    {
        if (this->Size != otherArray.Size)
            return false;
        for (int i = 0;i < this->Size;i++)
            if (*this->List[i] != *otherArray.List[i])
                return false;
        return true;
    }

    void Sort() // sorteaza folosind comparatia intre elementele din T
    {
        int i, j;
        for (i = 0;i < this->Size - 1;i++)
            for (j = i + 1;j < this->Size;j++)
                if (*this->List[i] > *this->List[j])
                {
                    T* aux = this->List[j];
                    this->List[j] = this->List[i];
                    this->List[i] = aux;
                }
    }
    void Sort(int(*compare)(const T&, const T&))// sorteaza folosind o functie de comparatie
    {
        int i, j;
        for (i = 0;i < this->Size - 1;i++)
            for (j = i + 1;j < this->Size;j++)
                if (compare(*this->List[i], *this->List[j]) > 0)
                {
                    T* aux = this->List[j];
                    this->List[j] = this->List[i];
                    this->List[i] = aux;
                }
    }
    void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
    {
        int i, j;
        for (i = 0;i < this->Size - 1;i++)
            for (j = i + 1;j < this->Size;j++)
                if (comparator->CompareElements(*this->List[i], *this->List[j]) > 0)
                {
                    T* aux = this->List[j];
                    this->List[j] = this->List[i];
                    this->List[i] = aux;
                }
    }

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {
        nu_sortat s;
        try
        {
            for (int i = 0;i < this->Size - 1;i++)
                for (int j = i + 1;j < this->Size;j++)
                    if (*this->List[i] > *this->List[j])
                        throw s;
            int st = 0, dr = this->Size - 1, mij;
            while (st <= dr)
            {
                mij = (st + dr) / 2;
                if (this->List[mij] != nullptr)
                {
                    if (*this->List[mij] == elem)
                        return mij;
                    else if (*this->List[mij] > elem)
                        dr = mij - 1;
                    else st = mij + 1;
                }
                
            }
            return -1;
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
    {
        nu_sortat s;
        try
        {
            for (int i = 0;i < this->Size - 1;i++)
                for (int j = i + 1;j < this->Size;j++)
                    if (compare(*this->List[i], *this->List[j]) > 0)
                        throw s;
            int st = 0, dr = this->Size - 1, mij;
            while (st <= dr)
            {
                mij = (st + dr) / 2;
                if (this->List[mij] != nullptr)
                {
                    if (compare(*this->List[mij], elem) == 0)
                        return mij;
                    if (compare(*this->List[mij], elem) > 0)
                        dr = mij - 1;
                    else st = mij + 1;
                }
                
            }
            return -1;
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }
    }
    int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
    {
        nu_sortat s;
        try
        {
            for (int i = 0;i < this->Size - 1;i++)
                for (int j = i + 1;j < this->Size;j++)
                    if (comparator->CompareElements(*this->List[i], *this->List[j]) > 0)
                        throw s;
            int st = 0, dr = this->Size - 1, mij;
            while (st <= dr)
            {
                mij = (st + dr) / 2;
                if (this->List[mij] != nullptr)
                {
                    if (comparator->CompareElements(*this->List[mij], elem) == 0)
                        return mij;
                    if (comparator->CompareElements(*this->List[mij], elem) > 0)
                        dr = mij - 1;
                    else st = mij + 1;
                }
                
            }
            return -1;
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }
    }
    int Find(const T& elem)
    {
        for (int i = 0; i < this->Size; i++)
            if (this->List[i] != nullptr)
            {
                //cout << *this->List[i]<<" ";
                if (*this->List[i] == elem)
                    return i;
            }
            //else cout << "am gasit nullptr la " << i << endl;
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
    {
        for (int i = 0;i < this->Size;i++)
            if (this->List[i] != nullptr)
            if (compare(*this->List[i], elem) == 0)
                return i;
        return -1;
    }
    int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
    {
        for (int i = 0;i < this->Size;i++)
            if (this->List[i] != nullptr)
            if (comparator->CompareElements(*this->List[i], elem) == 0)
                return i;
        return -1;
    }

    int GetSize() { return this->Size; }
    int GetCapacity() { return this->Capacity; }

    ArrayIterator<T> GetBeginIterator() { return ArrayIterator<T>(this->List, 0); }
    ArrayIterator<T> GetEndIterator() { return ArrayIterator<T>(this->List + this->Size, this->Size); }

    ArrayIterator<T>begin() { return ArrayIterator<T>(this->List, 0); };
    ArrayIterator<T>end() { return ArrayIterator<T>(this->List + this->Size, this->Size); };

};