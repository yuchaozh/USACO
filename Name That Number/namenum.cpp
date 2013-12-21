/*
ID: yuchaoz1
PROG: namenum
LANG: C++
*/
/**
 *Reference to others' answers. And become simpler.
 *look up in the dict.txt to find out all potential name       
 *according to the serial number rather than using the serial 
 *number to convert into string and look
 *up in the dict.txt
 **/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string charToNumber(char r)
{
	if ((r == 'A') || (r == 'B') || (r == 'C'))
		return "2";
	else if ((r == 'D') || (r == 'E') || (r == 'F'))
		return "3";
	else if ((r == 'G') || (r == 'H') || (r == 'I'))
		return "4";
	else if ((r == 'J') || (r == 'K') || (r == 'L'))
		return "5";
	else if ((r == 'M') || (r == 'N') || (r == 'O'))
		return "6";
	else if ((r == 'P') || (r == 'R') || (r == 'S'))
		return "7";
	else if ((r == 'T') || (r == 'U') || (r == 'V'))
		return "8";
	else if ((r == 'W') || (r == 'X') || (r == 'Y'))
		return "9";
	else
		return "0";
}

/**return string is easy to compare**/
string stringToNumber(string str)
{
	string name = "";
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		string number = charToNumber(str[i]);
		name.insert(i, number);
	}
	return name;
}

int main()
{
	ifstream inputFile;
	ifstream dict;
	ofstream outputFile;
	inputFile.open("namenum.in");
	dict.open("dict.txt");
	string number;
	bool exist = false;
	string potentialName;
	inputFile>>number;
	outputFile.open("namenum.out");
	while(dict>>potentialName)
	{	
		if (stringToNumber(potentialName) == number)
		{
			exist = true;
			outputFile<<potentialName<<endl;
		}
	}
	
	if (exist == false)
	{
		outputFile<<"NONE"<<endl;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}
