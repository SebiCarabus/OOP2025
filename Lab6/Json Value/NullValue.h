#pragma once
#include "JsonValue.h"
class NullValue : public JsonValue
{
private:
public:
	NullValue();
	~NullValue();
	void print(std::ostream& out) override;
};

