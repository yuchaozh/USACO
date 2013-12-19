/*
ID: yuchaoz1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findPattern(string* a, string* b, int arraySize)
{
	string* rotation_90 = new string[arraySize];
	string* rotation_180 = new string[arraySize];
	string* rotation_270 = new string[arraySize];
	string* reflection = new string[arraySize];
	string* re_ro_90 = new string[arraySize];
	string* re_ro_180 = new string[arraySize];
	string* re_ro_270 = new string[arraySize];
	bool number1 = true;
	bool number2 = true;
	bool number3 = true;
	bool number4 = true;
	bool number5 = true;
	bool number6 = true;
		
	//#1 90 Degree Rotation
	for (int i = 0; i < arraySize; i++)
	{
		string outcome = "";
		string temp;
		for (int j = 0; j < arraySize; j++)
		{
			temp = a[j][i];
			outcome.insert(0, temp);
		}
		rotation_90[i] = outcome;
	}
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (rotation_90[i][j] != b[i][j])
			{
				number1 = false;
			}
		}
	}
	if (number1 == true)
		return 1;
	
		//#2 180 Degree Rotation
	for (int i = arraySize - 1; i >= 0; i--)
	{
		string outcome = "";
		string temp;
		for (int j = 1; j <= arraySize; j++)
		{
			temp = a[i][j - 1];
			outcome.insert(0, temp);
		}
		rotation_180[arraySize - 1 - i] = outcome;
	}
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (rotation_180[i][j] != b[i][j])
			{
				number2 = false;
			}
		}
	}
	if (number2 == true)
		return 2;
		
	//#3 90 Degree Rotation right
	for (int i = arraySize - 1; i >= 0; i--)
	{
		string outcome = "";
		string temp;
		for (int j = 0; j < arraySize; j++)
		{
			temp = a[j][i];
			outcome.insert(j, temp);
		}
		rotation_270[arraySize -1 - i] = outcome;
	}
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (rotation_270[i][j] != b[i][j])
			{
				number3 = false;
			}
		}
	}
	if (number3 == true)
		return 3;
		
	//#4 Reflection
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (b[i][j] != a[i][arraySize - j - 1])
				number4 = false;
		}
	}
	if (number4 == true)
		return 4;
		
	//#5 Combination
	for (int i = 0; i < arraySize; i++)
	{
		string outcome = "";
		string temp;
		for (int j = 0; j < arraySize; j++)
		{
			temp = a[i][j];
			outcome.insert(0, temp);
		}
		reflection[i] = outcome;
	}
	/**
	cout<<"refelction: "<<endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout<<reflection[i]<<endl;
	}
	**/
	//re_ro_270
	for (int i = arraySize - 1; i >= 0; i--)
	{
		string outcome = "";
		string temp;
		for (int j = 0; j < arraySize; j++)
		{
			temp = reflection[j][i];
			outcome.insert(j, temp);
		}
		re_ro_270[arraySize -1 - i] = outcome;
	}
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (re_ro_270[i][j] != b[i][j])
			{
				number5 = false;
			}
		}
	}
	if (number5 == true)
		return 5;
	//re_ro_90
	number5 = true;
	for (int i = 0; i < arraySize; i++)
	{
		string outcome = "";
		string temp;
		for (int j = 0; j < arraySize; j++)
		{
			temp = reflection[j][i];
			outcome.insert(0, temp);
		}
		re_ro_90[i] = outcome;
	}
	/**
	cout<<"re_ro_90: "<<endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout<<re_ro_90[i]<<endl;
	}	
	**/
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (re_ro_90[i][j] != b[i][j])
			{
				number5 = false;
			}
		}
	}
	if (number5 == true)
		return 5;
	//re_ro_180
	number5 = true;
	for (int i = arraySize - 1; i >= 0; i--)
	{
		string outcome = "";
		string temp;
		for (int j = 1; j <= arraySize; j++)
		{
			temp = reflection[i][j - 1];
			outcome.insert(0, temp);
		}
		re_ro_180[arraySize - 1 - i] = outcome;
	}
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (re_ro_180[i][j] != b[i][j])
			{
				number5 = false;
			}
		}
	}
	if (number5 == true)
		return 5;
		
	//#6 No Change
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (a[i][j] != b[i][j])
			{
				number6 = false;
			}
		}
	}
	if (number6 == true)
		return 6;
	
	if ((number1 == false) && (number2 == false) && (number3 == false) && (number4 == false) && (number5 == false) && (number6 == false))
		return 7;
}



int main()
{
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open("transform.in");
	int size;
	int pattern = 0;
	string content;
	inputFile>>size;
	//initiate a string array
	string* matrix1 = new string[size];
	string* matrix2 = new string[size];
	for(int i = 0; i < size; i++)
	{
		inputFile>>content;
		matrix1[i] = content;
		//cout<<matrix1[i]<<endl;
	}
	for(int i = 0; i < size; i++)
	{
		inputFile>>content;
		matrix2[i] = content;
		//cout<<matrix2[i]<<endl;
	}
	
	pattern = findPattern(matrix1, matrix2, size);
	
	
	outputFile.open("transform.out");
	//cout<<pattern<<endl;
	outputFile<<pattern<<endl;
	inputFile.close();
	outputFile.close();
	return 0;
}
