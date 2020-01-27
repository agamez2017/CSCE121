#include <iostream>
#include "std_lib_facilities.h"
class InvalidInput { };
using namespace std;
int main()
{
	cout<<"Enter numbers (followed by a semicolon and enter):\n";
	vector<double> temps; 
	for(double temp; cin>>temp;)
	{
		temps.push_back(temp);
	}
	sort(temps);
	double median = 0;
	if (temps.size() == 0)
	{
		throw InvalidInput();
	}
	if(temps.size() % 2 == 0)
	{
	median=(temps[temps.size()/2] + temps[(temps.size()/2)-1])/2;
	}
	else 
		median= temps[temps.size()/2];
	cout<<"Median temperature: "<<median<<'\n';
	
	
}