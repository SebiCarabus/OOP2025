#pragma once
class Movie
{
private:
	char* name;
	int year,length;
	double score;
public:
	Movie();
	const char* get_name();
	void set_name(const char* s);
	int get_year();
	void set_year(int x);
	int get_length();
	void set_length(int x);
	double get_score();
	void set_score(double x);
	int get_passed_years();
};

