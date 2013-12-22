/*
ID: yuchaoz1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
 
using namespace std;

/** trun int into string **/
string numberToChar(int num)
{
	stringstream ss;
   	ss << num;
   	string cString = ss.str();
   	return cString;
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
	ofstream output("dualpal.out");
	ifstream input("dualpal.in");
	int number;
	int baseNumber;
	vector<int> palindrome;
	input>>number;
	input>>baseNumber;
	string pal;
	for(int i = baseNumber + 1; ; ++i)
	{
		bool first = false;
		bool second = false;
		for(int j = 2; j <= 10; j++)
		{
			pal = divideToBase(i, j);
			if(pal == reverseString(pal))
   			{
   				if (first == false)
   				{
   					first = true;
   					continue;
   				}
   				else
   				{
   					second = true;
   					palindrome.push_back(i);
   					break;
   				}
   			}
   		}
   		if (palindrome.size() == number)
   		{
   			break;
   		}
 	}
 	for (int i = 0; i < number; i++)
 	{
 		output<<palindrome[i]<<endl;
 	}
 	output.close();
 	input.close();
 	return 0;
}
