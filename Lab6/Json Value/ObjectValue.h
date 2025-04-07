#pragma once
#include "JsonValue.h"
#include <cstring>
class ObjectValue : public JsonValue
{
private:
	int nr;
	char** name;
	JsonValue** v;
public:
	ObjectValue();
	~ObjectValue();
	void add(const char* sn,JsonValue* p);
	void print(std::ostream& out) override;
	operator unsigned() const;
};

