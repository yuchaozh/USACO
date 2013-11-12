/*
ID: yuchaoz1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool equal(int a, int b)
{
	if (a%47 == b%47)
		return true;
	else
		return false;
}

int main()
{
	ofstream output;
	ifstream input;
	input.open("ride.in");
	output.open("ride.out");

	string comet, group;
	int comet_asc = 1, group_asc = 1;
	input>>comet>>group;
	
	for(int i = 0; i < comet.length(); i++)
	{
		comet_asc = comet_asc * ((int) comet[i] - 64);
	}

	for (int a = 0; a < group.length(); a++)
	{
		group_asc = group_asc * ((int) group[a] - 64);
	}

	if (equal(comet_asc, group_asc))
	{
		output<<"GO"<<endl;
	}
	else
	{
		output<<"STAY"<<endl;
	}
	input.close();
	output.close();
	return 0;
}	
	
