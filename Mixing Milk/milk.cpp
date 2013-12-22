/*
ID: yuchaoz1
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
 
using namespace std;

class Milk
{
public:
	int price;
	int amount;
	
	Milk()
	{
		price = 0;
		amount = 0;
	}
};

/** vector sort by price**/
bool sortByPrice(const Milk &v1, const Milk &v2)
{	
	return v1.price < v2.price;
}
	
int main()
{
	ofstream outputFile("milk.out");
	ifstream inputFile("milk.in");
	int totalPrice = 0;
	int totalAmount;
	int farmers;
	int inputPrice;
	int inputAmount;
	vector<Milk> milk;
	inputFile>>totalAmount;
	inputFile>>farmers;
	/** vector push back (own class)**/
	while(inputFile>>inputPrice>>inputAmount)
	{
		Milk milk1;
		milk1.price = inputPrice;
		milk1.amount = inputAmount;
		milk.push_back(milk1);
	}
	sort(milk.begin(), milk.end(), sortByPrice);
	for (int i = 0; i < farmers; i++)
	{
		if (totalAmount > 0)
		{
			if (totalAmount < milk[i].amount)
			{	
				totalPrice = milk[i].price * totalAmount + totalPrice;
				totalAmount = totalAmount - totalAmount;
			}
			else
			{	
				totalPrice = milk[i].price * milk[i].amount + totalPrice;
				totalAmount = totalAmount - milk[i].amount;
			}
		}
		else
		{
			break;
		}
	}
	outputFile<<totalPrice<<endl;
	outputFile.close();
	inputFile.close();
	return 0;
}
	
	
	
	
