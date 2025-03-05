#include "GlobalFunctions.h"
#include "Movie.h"
#include <cstring>
int movie_compare_name(Movie a, Movie b)
{
	return strcmp(a.get_name(), b.get_name());
}
int movie_compare_year(Movie a, Movie b)
{
	int n1= a.get_year(), n2 = b.get_year();
	if (n1 < n2) return -1;
	if (n1 > n2) return 1;
	return 0;
}
int movie_compare_score(Movie a, Movie b)
{
	double n1 = a.get_score(), n2 = b.get_score();
	if (n1 < n2) return -1;
	if (n1 > n2) return 1;
	return 0;
}
int movie_compare_length(Movie a, Movie b)
{
	int n1 = a.get_length(), n2 = b.get_length();
	if (n1 < n2) return -1;
	if (n1 > n2) return 1;
	return 0;
}
int movie_compare_passed_years(Movie a, Movie b)
{
	int n1 = a.get_passed_years(), n2 = b.get_passed_years();
	if (n1 < n2) return -1;
	if (n1 > n2) return 1;
	return 0;
}