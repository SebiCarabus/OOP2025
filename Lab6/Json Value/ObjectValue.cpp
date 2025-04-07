#include "ObjectValue.h"
ObjectValue::ObjectValue() : nr(0) {}
ObjectValue::~ObjectValue()
{
	for (int i = 0;i < this->nr;i++)
	{
		delete this->v[i];
		delete this->name[i];
	}
	delete[]this->v;
	delete[]this->name;
}
void ObjectValue::add(const char*sn,JsonValue* p)
{
	if (this->nr >= 16)return;
	this->nr++;
	if (this->nr == 1)
	{
		this->name = new char* [1];
		this->name[0] = new char[strlen(sn) + 1];
		int j;
		for (j = 0;j < strlen(sn);j++)
			this->name[0][j] = sn[j];
		this->name[0][j] = '\0';
		this->v = new JsonValue * [1];
		this->v[0] = p;
		return;
	}
	char** cn = new char* [this->nr + 1];
	JsonValue** c = new JsonValue * [this->nr + 1];
	int i;
	for (i = 0;i < this->nr - 1;i++)
	{
		cn[i] = new char[strlen(this->name[i]) + 1];
		cn[i] = this->name[i];
		c[i] = this->v[i];
	}
	int j;
	cn[i] = new char[strlen(sn) + 1];
	for (j = 0;j < strlen(sn);j++)
		cn[i][j] = sn[j];
	cn[i][j] = '\0';
	c[i] = p;
	delete[]this->name;
	delete[]this->v;
	this->name = cn;
	this->v = c;
}
void ObjectValue::print(std::ostream& out)
{
	int i;
	out << "{ ";
	for (i = 0;i < this->nr - 1;i++)
	{
		out << this->name[i];
		out << ": ";
		this->v[i]->print(out);
		out << ", ";
	}
	out << this->name[i] << ": ";
	this->v[i]->print(out);
	out << " }";
}

ObjectValue::operator unsigned() const 
{
	return this->nr;
}

