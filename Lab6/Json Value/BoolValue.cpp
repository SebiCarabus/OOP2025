#include "BoolValue.h"
BoolValue::BoolValue(const bool value)
{
	this->bv = new bool(value);
}
BoolValue::BoolValue() : BoolValue(true){}
BoolValue::~BoolValue() { delete this->bv; }
void BoolValue::print(std::ostream& out)
{
	out << *this->bv;
}