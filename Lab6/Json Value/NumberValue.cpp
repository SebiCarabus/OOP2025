#include "NumberValue.h"
NumberValue::NumberValue(const int value)
{
	this->nv = new int(value);
}
NumberValue::NumberValue() : NumberValue(0) {}
NumberValue::~NumberValue() { delete this->nv; }
void NumberValue::print(std::ostream& out)
{
	out << *this->nv;
}
