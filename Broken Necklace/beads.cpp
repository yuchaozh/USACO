/*
ID: yuchaoz1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream inputFile;
	ofstream outputFile;
	int beadsNumber;
	string beads;
	inputFile.open("beads.in");
	inputFile>>beadsNumber;
	inputFile>>beads;
	inputFile.close();
	
	cout<<"beadsNumber: "<<beadsNumber<<endl;
	cout<<"beads: "<<beads<<endl;
	
	int current;
	int max = 0;
	char color;
	bool second;
	
	for (int i = 0; i < beadsNumber; i++)
	{
		current = 0;
		color = 'w';
		second = false;
		for (int j = 0; j < beadsNumber; j++)
		{
			const char current_c = beads[(i + j) % beadsNumber];
			if (current_c != 'w')
			{
				if (color == 'w')
				{
					color = current_c;
				}
				else if (color != current_c)
				{
					if (second)
						break;
					else
					{
						color = current_c;
						second = true;
					}
				}
			}
			current++;
		}
		if (current > max)
			max = current;
	}
	
	outputFile.open("beads.out");
	outputFile<<max<<endl;
	cout<<max<<endl;
	outputFile.close();
	return 0;
}
