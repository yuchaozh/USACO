/*
ID: yuchaoz1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
	string name;
	int money;
	
	Person()
	{
		name = "";
		money = 0;
	}
};

vector<Person> persons;
int personNumber = 0;

void divideMoney(int sum, string name)
{
	for (int i = 0; i < personNumber; i ++)
	{
		if (persons[i].name == name)
			persons[i].money = persons[i].money + sum;
	}
}


int main()
{
	ifstream inputFile;
	ofstream outputFile;
	
	int sumPerson;
	int sumMoney;
	int averageMoney;
	int dividePersons;
	int currentPerson;
	int rest;
	string input;
	inputFile.open("gift1.in");
	inputFile>>personNumber;
	persons.resize(100);
	
	//initate person array
	for (int i = 0; i < personNumber; i++)
	{
		inputFile>>input;
		persons[i].name = input;
	}
	while(inputFile>>input)
	{
		for (int i = 0; i < personNumber; i++)
		{
			if (persons[i].name == input)
				currentPerson = i;
		}
		inputFile>>sumMoney>>sumPerson;
		if (sumPerson == 0) continue;
		if (sumMoney % sumPerson != 0)
		{
			averageMoney = sumMoney / sumPerson;
			rest = sumMoney - averageMoney * sumPerson;
			persons[currentPerson].money = persons[currentPerson].money - sumMoney + rest;
		}
		else
		{
			averageMoney = sumMoney / sumPerson;
			persons[currentPerson].money = persons[currentPerson].money - sumMoney;
		}
		for (int i = 0; i < sumPerson; i++)
		{
			inputFile>>input;
			divideMoney(averageMoney, input);
		}
	}
	
	outputFile.open("gift1.out");
	for (int i = 0; i < personNumber; i++)
	{
		outputFile<<persons[i].name<<" "<<persons[i].money<<endl;
	}
	return 0;

}
