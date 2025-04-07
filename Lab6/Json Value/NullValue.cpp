#include "NullValue.h"
NullValue::NullValue(){}
NullValue::~NullValue() {}
void NullValue::print(std::ostream& out)
{
	out << "null";
}
