#pragma once
#include "JsonValue.h"
class ArrayValue : public JsonValue
{
private:
	int nr;
	JsonValue** v;
public:
	ArrayValue();
	~ArrayValue();
	void add(JsonValue *p);
	void print(std::ostream& out) override;
};

