#include <iostream>
#include<fstream>
#include<string>
#include<map>
#include<queue>
#include<vector>


using namespace std;

ifstream in("citire.txt");

void desparte_in_cuvinte(string propozitie, map<string, int>& contorizare,vector<string>&vm)
{
	char c;
	int i, n = propozitie.length();
	string cuv="";
	for (i = 0;i < n;i++)
	{
		c = propozitie.at(i);
		if (c == ' ' || c == '.' || c == '!' || c == '?' || c=='\n')
		{
			if (cuv.size() != 0)
			{
				contorizare[cuv]++;
				if (contorizare[cuv] == 1)
					vm.push_back(cuv);
			}
			cuv = "";
		}
		else
		{
			if (c >= 'A' && c <= 'Z')
				c = c - 'A' + 'a';
			cuv = cuv + c;
		}
		
	}

}

class comparator_custom
{
public:
	bool operator()(pair<string, int> a, pair<string, int> b)
	{
		if (a.second != b.second)
			return (a.second < b.second);
		return a.first > b.first;
	}
};

int main()
{
	int nr=0;
	string cuv,propozitie="";
	while (in >> cuv)
	{
		nr++;
		if (nr != 1)
			propozitie = propozitie + " " + cuv;
		else
			propozitie = cuv;
	}
	cout << endl << propozitie<<endl<<endl;
	map<string, int> contorizare;
	vector<string> vm;
	desparte_in_cuvinte(propozitie, contorizare,vm);
	priority_queue<pair<string,int>, vector<pair<string,int>>, comparator_custom> coada;
	vector<string>::iterator it;
	for (it = vm.begin();it != vm.end();it++)
	{
		cout <<'"'<< *it <<'"'<< " : " << contorizare[*it] << endl;
		coada.push(make_pair(*it, contorizare[*it]));
	}	
	cout << endl;
	while (!coada.empty())
	{
		auto iq = coada.top();
		cout << iq.first << " => " << iq.second<<endl;
		coada.pop();
	}

}
