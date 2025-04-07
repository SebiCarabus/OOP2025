#pragma once
#include "Weather.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
class Circuit
{
private:
	int l,nr_m,nr_testat;
	Weather w;
	Car** cars;
	double* d_max;
	bool* a_incheiat;
public:
	Circuit();
	~Circuit();
	void SetLength(int length);
	void SetWeather(Weather wet);
	void AddCar(Car *c);
	void Race();
	void ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	void ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
};

