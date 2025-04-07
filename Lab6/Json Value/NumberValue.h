#pragma once
#include "JsonValue.h"
class NumberValue : public JsonValue
{
private:
	int *nv;
public:
	NumberValue(const int value);
	NumberValue();
	~NumberValue();
	void print(std::ostream& out) override;
};

