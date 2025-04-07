#pragma once
#include "JsonValue.h"
#include <cstring>
class StringValue : public JsonValue
{
private:
		char* s;
public:
	StringValue(const char* value);
	StringValue();
	~StringValue();
	void print(std::ostream& out) override;
};

