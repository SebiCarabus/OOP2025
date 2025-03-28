#pragma once
class Number
{
private:
	int nr,lg;
	char* nb;
	int base;
public:
	Number(const char* value, int base);
	Number(int value);
	Number(const Number & x);///copy constructor
	Number(Number && x);///move constructor
	~Number();///Destructor

	friend Number operator + (const Number& a,const Number& b);
	friend Number operator - (const Number& a, const Number& b);
	bool operator < (const Number& b);
	bool operator > (const Number& b);
	bool operator <= (const Number& b);
	bool operator >= (const Number& b);
	bool operator == (const Number& b);
	bool operator != (const Number & b);
	void operator += (const Number & b);
	void operator -= (const Number & b);
	Number& operator = (const char* b);
	Number& operator = (const int b);
	Number& operator = (const Number& b);
	Number operator -- ();
	Number operator -- (int value);
	char operator [](int index);

	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount();
	int GetBase();
	int GetBase10();
};

