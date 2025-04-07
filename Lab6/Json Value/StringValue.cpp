#include "StringValue.h"
StringValue::StringValue(const char* value)
{
	if (strlen(value) > 255)return;
	this->s = new char[strlen(value) + 1];
	int i;
	for (i = 0;i < strlen(value);i++)
		this->s[i] = value[i];
	this->s[i] = '\0';
}
StringValue::StringValue() : StringValue("") {}
StringValue::~StringValue() { delete[]this->s;}
void StringValue::print(std::ostream& out)
{
	out << this->s;
}
