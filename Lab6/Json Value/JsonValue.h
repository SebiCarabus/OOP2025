#pragma once
#include<iostream>
class JsonValue
{
public:
    virtual ~JsonValue() {};
    virtual void print(std::ostream& out) = 0;
};


