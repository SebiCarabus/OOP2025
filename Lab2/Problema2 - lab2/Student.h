#pragma once

class Student
{
private:
	char name[50];
	float math, eng, histo;
public:
	Student();
	void set_name(char s[50]);
	char* get_name();
	void set_math(float x);
	float get_math();
	void set_eng(float x);
	float get_eng();
	void set_histo(float x);
	float get_histo();
	float get_avg();
};
