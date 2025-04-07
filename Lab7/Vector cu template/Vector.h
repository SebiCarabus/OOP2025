#pragma once
#include <iostream>
template<class T>
class Vector
{
	T* v;
	int size;
public:
	Vector()
	{
		this->size = 0;
		this->v = nullptr;
	}
	Vector(const Vector& d)
	{
		if (d.v != nullptr)
		{
			this->size = d.size;
			if (this->v != nullptr)
				delete[]this->v;
			this->v = new T[d.size];
			for (int i = 0;i < d.size;i++)
				this->v[i] = d.v[i];
		}
		else
		{
			this->size = 0;
			if (this->v != nullptr)
			{
				delete[]this->v;
				v = nullptr;
			}
		}
	}
	Vector(Vector&& d)
	{
		if (d.v != nullptr)
		{
			this->size = d.size;
			if (this->v != nullptr)
				delete[]this->v;
			this->v = new T[d.size];
			for (int i = 0;i < d.size;i++)
				this->v[i] = d.v[i];
		}
		else
		{
			this->size = 0;
			if (this->v != nullptr)
			{
				delete[]this->v;
				v = nullptr;
			}
		}
		d.v = nullptr;
	}
	~Vector()
	{
		delete[]this->v;
		this->v = nullptr;
		this->size = 0;
	}
	T& operator[](int index)
	{
		if (index < 0 || index >= this->size)
			throw std::exception("Problema la index");
		return this->v[index];
	}
	void insert(int index, T val)
	{
		if (index < 0)
			index = 0;
		else if (index >= this->size)
			index = this->size;
		T* x = new T[this->size + 1];
		int i;
		for (i = 0;i < index;i++)
			x[i] = this->v[i];
		for (i = index + 1;i <= this->size;i++)
			x[i] = this->v[i - 1];
		x[index] = val;
		delete[]this->v;
		this->size++;
		this->v = x;
	}
	void remove(int index)
	{
		if (index < 0)
			index = 0;
		else if (index >= this->size)
			index = this->size;
		if (this->size == 0)
			return;
		T* x = new T[this->size - 1];
		int i;
		for (i = 0;i < index;i++)
			x[i] = this->v[i];
		for (i = index;i < this->size-1;i++)
			x[i] = this->v[i + 1];
		delete[]this->v;
		this->size--;
		this->v = x;
	}
	void sort(int (*func)(int x, int y))
	{
		T aux;
		for (int i = 0;i < this->size-1;i++)
			for(int j=i+1;j<this->size;j++)
				if (func(this->v[j],this->v[i]) == 1)
				{
					aux = this->v[j];
					this->v[j] = this->v[i];
					this->v[i] = aux;
				}
	}
	void print()
	{
		for (int i = 0;i < this->size;i++)
			std::cout << this->v[i] << " ";
		std::cout << std::endl;
	}
};
