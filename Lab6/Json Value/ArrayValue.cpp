#include "ArrayValue.h"
ArrayValue::ArrayValue() : nr(0) {}
ArrayValue::~ArrayValue() 
{
	for(int i=0;i<this->nr;i++)
		delete []this->v[i];
	delete[]this->v;
	this->v = nullptr;
	this->nr = 0;
}
void ArrayValue::add(JsonValue *p)
{
	if (this->nr >= 16)return;
	this->nr++;
	if (this->nr == 1)
	{
		this->v = new JsonValue * [this->nr + 1];
		this->v[0] = p;
		return;
	}
	JsonValue** c = new JsonValue*[this->nr+1];
	int i;
	for (i = 0;i < this->nr - 1;i++)
		c[i] = this->v[i];
	c[i] = p;
	delete []this->v;
	this->v = c;
}
void ArrayValue::print(std::ostream& out)
{
	out << "[";
	int i;
	for (i = 0;i < this->nr - 1;i++)
	{
		this->v[i]->print(out);
		out << ", ";
	}
	this->v[i]->print(out);
	out << "]";
}
