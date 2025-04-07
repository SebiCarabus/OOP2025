#pragma once
#include "JsonValue.h"
class BoolValue : public JsonValue
{
private:
	bool *bv;
public:
	BoolValue(const bool value);
	BoolValue();
	~BoolValue();
	void print(std::ostream& out) override;
};

