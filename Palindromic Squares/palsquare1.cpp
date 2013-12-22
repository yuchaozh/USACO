/*
ID: yuchaoz1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
 
using namespace std;

/** trun int into string **/
string numberToChar(int num)
{
	string turn;
	if(num >= 10)
    {
    	char c = (char) (num - 10 + 65);
    	//wrong: string turn = c;
    	turn = c;
    	return turn;
    }
    else
    {
		stringstream ss;
    	ss << num;
    	string cString = ss.str();
    	return cString;
    }
}

string divideToBase(int number, int base)
{
	string baseNumber;
	int reminder = 999;
	int left = number;
	while (left >= base)
	{
		reminder = left % base;
		left = left / base;
		baseNumber.insert(0, numberToChar(reminder));
	}
	baseNumber.insert(0, numberToChar(left));
	return baseNumber;
}
	
string reverseString(string str)
{
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	ofstream output("palsquare.out");
	ifstream input("palsquare.in");
	int base;
	string n;
	string nSquare;
	input>>base;
	for(int i = 1; i <= 300; ++i)
	{
		n = divideToBase(i, base);
  		nSquare = divideToBase(i * i, base);
		if(nSquare == reverseString(nSquare))
   		output << n << " " << nSquare << endl;
 	}
 	output.close();
 	input.close();
 	return 0;
}
