/*
ID: yuchaoz1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int count[7] = {0};

int thirtyOne(int predays)
{
	int thirteenth = predays + 13;
	int day = thirteenth % 7;
	count[day]++;
	return predays + 31;
}

int thirty(int predays)
{
	int thirteenth = predays + 13;
	int day = thirteenth % 7;
	count[day]++;
	return predays + 30;
}

int leap(int predays, int year)
{
	bool leap = false;
	//centry year
	if (year % 100 == 0)
	{
		if (year % 400 == 0)
		{
			leap = true;
		}
	}
	//not centry year
	else
	{
		if (year % 4 == 0)
			leap = true;
	}
	if (leap == true)
	{
		int thirteenth = predays + 13;
		int day = thirteenth % 7;
		count[day]++;
		return predays + 29;
	}
	else
	{
		int thirteenth = predays + 13;
		int day = thirteenth % 7;
		count[day]++;
		return predays + 28;
	}
}

int main()
{
	ifstream inputFile;
	ofstream outputFile;
	int input;
	inputFile.open("friday.in");
	inputFile>>input;
	inputFile.close();
	int totalMonths = input * 12;
	int month;
	int monthCount = 0;
	int year = 1899;
	int previousDays = 0;
	for (int i = 0; i <totalMonths; i++)
	{
		monthCount++;
		month = monthCount % 12;
		if (month == 1)
			year++;
		
	switch(month)
	{
		case 1:
		{
			previousDays = thirtyOne( previousDays);
			break;
		}
		case 2:
		{
			previousDays = leap( previousDays,  year);
			break;
		}
		case 3:
		{
			previousDays = thirtyOne( previousDays);
			break;
		}
		case 4:
		{
			previousDays = thirty( previousDays);
			break;
		}
		case 5:
		{
			previousDays = thirtyOne( previousDays);
			break;
		}
		case 6:
		{
			previousDays = thirty( previousDays);
			break;
		}
		case 7:
		{
			previousDays = thirtyOne( previousDays);
			break;
		}
		case 8:
		{
			previousDays = thirtyOne( previousDays);
			break;
		}
		case 9:
		{
			previousDays = thirty( previousDays);
			break;
		}
		case 10:
		{
			previousDays = thirtyOne( previousDays);
			break;
		}
		case 11:
		{
			previousDays = thirty( previousDays);
			break;
		}
		case 0:
		{
			previousDays = thirtyOne( previousDays);
			break;
		}
		default:
			cout<<"error"<<endl;
	}
	}
	
	outputFile.open("friday.out");
	outputFile<<count[6]<<" "<<count[0]<<" "<<count[1]<<" "<<count[2]<<" "<<count[3]<<" "<<count[4]<<" "<<count[5]<<endl;
	outputFile.close();
	return 0;
}
