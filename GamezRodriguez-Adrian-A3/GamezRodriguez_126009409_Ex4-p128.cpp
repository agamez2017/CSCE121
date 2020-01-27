#include <iostream>
#include "std_lib_facilities.h"


using namespace std;
int main()
{
	char choice;
	int lowerbound = 1; 
	int upperbound = 100;
	cout<<"Think of a integer between 1 and 100 \n";
	cout<<"Now lets begin:\n";
	while(lowerbound < upperbound )
	{
		int mid = (lowerbound + upperbound )/2;
		cout<< "Is your number greater than "<<mid<<"? (Enter 'y' for yes and 'n' for no)\n";
		cin>>choice;
		if( choice == 'y' || choice == 'Y')
		{
			lowerbound = mid +1;
		}
		else
		{
			upperbound = mid ;
			
		}
	}
	cout<<"Your number is "<<lowerbound<<"!\n";
}