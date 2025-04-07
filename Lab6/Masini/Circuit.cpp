#include "Circuit.h"
#include <stdio.h>
Circuit::Circuit()
{
	this->nr_m = 0;
	this->nr_testat = 0;
	this->l = 0;
	this->w = Weather::Sunny;
}
Circuit::~Circuit()
{
	for (int i = 0;i < this->nr_m;i++)
		delete this->cars[i];
	delete[]this->cars;
	delete[]this->a_incheiat;
	delete[]this->d_max;
}
void Circuit::SetLength(int length)
{
	this->l = length;
}
void Circuit::SetWeather(Weather wet)
{
	this->w = wet;
}
void Circuit::AddCar(Car *c)
{
	if (this->nr_m <= 0)
	{
		this->d_max = new double [1];
		this->a_incheiat = new bool[1];
		this->d_max[0] = 0.0;
		this->a_incheiat[0] = false;
		this->nr_m = 1;
		this->cars = new Car*[1];
		this->cars[0] = c;
	}
	else
	{
		this->nr_m++;
		Car** n_cars = new Car * [this->nr_m + 1];
		double* d_n = new double [this->nr_m + 1];
		bool* b_n = new bool [this->nr_m + 1];
		for (int i = 0;i < this->nr_m - 1;i++)
		{
			n_cars[i] = this->cars[i];
			d_n[i] = this->d_max[i];
			b_n[i] = this->a_incheiat[i];
		}	
		n_cars[this->nr_m - 1] = c;
		d_n[this->nr_m - 1] = 0.0;
		b_n[this->nr_m - 1] = false;
		delete []this->cars;
		delete[]this->d_max;
		delete[]this->a_incheiat;
		this->cars = new Car * [this->nr_m + 1];
		this->cars = n_cars;
		this->d_max=new double [this->nr_m + 1];
		this->d_max = d_n;
		this->a_incheiat = new bool[this->nr_m + 1];
		this->a_incheiat = b_n;
	}
}
void Circuit::Race()
{
	if (this->nr_m == 0)
		printf("Nici o masina nu concureaza!\n\n");
	else
	{
		this->nr_testat = this->nr_m;
		for (int i = 0;i < this->nr_m;i++)
		{
			this->d_max[i] = (double)(this->cars[i]->get_f_capacity() * 100 / this->cars[i]->get_f_consumtion());
			if (this->d_max[i] >= this->l)
				this->a_incheiat[i] = true;
			else this->a_incheiat[i] = false;
		}
	}
}

void Circuit::ShowFinalRanks()
{
	Car** sol = new Car * [this->nr_m + 1];
	Car *c_aux;
	double* time = new double[this->nr_m + 1],aux,dmax;
	int i, j, k = 0;
	unsigned int vreme = static_cast<unsigned int>(this->w);/// extragem valoarea din spatele entitatii weather

	for (int i = 0;i < this->nr_testat;i++)
		if(this->a_incheiat[i]==true)
	{
			
			sol[k] = this->cars[i];
			unsigned int viteza=sol[k]->speed_i(vreme);
			double dist =(double) this->l;
			time[k] = (double)(dist /viteza);
			k++;
	}
	///sortam descrescator in functie de timpul de executie
	for (i = 0;i < k - 1;i++)
	{
		for(j=i+1;j<k;j++)
			if (time[i] < time[j])
			{
				c_aux = sol[i];
				aux = time[i];
				sol[i]=sol[j];
				time[i] = time[j];
				sol[j] = c_aux;
				time[j] = aux;
			}
	}
	for (i = 0;i < k;i++)
		printf("%s  time: %f\n", sol[i]->get_name(), time[i]);
	printf("\n");
	delete[]time;
	delete[]sol;

}
void Circuit::ShowWhoDidNotFinish() 
{
	Car** sol = new Car * [this->nr_m + 1];
	double aux, dmax;
	int i, j;
	unsigned int vreme = static_cast<unsigned int>(this->w);/// extragem valoarea din spatele entitatii weather
	int k = 0;
	for (int i = 0;i<this->nr_testat;i++)
		if (this->a_incheiat[i]==false)
		{
			sol[k] = this->cars[i];
			k++;
		}
	if (k == 0)
	{
		printf("Nu sunt masini care nu au ajuns la linia de finish!\n\n");
	}
	else
	{
		printf("Masinile care nu au reusit sa termine cursa:\n");
		for (i = 0;i < k;i++)
			printf("%s\n", sol[i]->get_name());
		printf("\n");
	}

	delete[]sol;

}// it is possible that some cars don't have enough fuel to finish the circuit*/