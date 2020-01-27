#include <iostream>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h"
using namespace std;
//Adrian Gamez-Rodriguez
//UIN: 126009409
//Trying to solve question 10. Turn all inputs into output with correct mathematical operation and result.
int main()
{
	string operation;
	double a;
	double b;
	cout<<"Enter an operation followed by two values: (follwed by Enter)\n";
	cin>>operation>>a>>b;
	if(operation.at(0) == 43 || operation.at(0)==112)
	{
	 double sum = a + b;
	 cout<<"The sum of the two values is "<<sum<<".\n";
	}
	if(operation.at(0) == 45 || (operation.at(0) == 109 && operation.at(1)==105))
	{
	double diff = a - b;
	cout<<"The difference of the two values is "<<diff<<".\n";
	}
	if(operation.at(0)== 42 || (operation.at(0) == 109 && operation.at(1) == 117))
	{
		double prod= a*b;
	cout<<"The product of the two values is "<<prod<<".\n";
	}
	if(operation.at(0)==47|| operation.at(0) == 100 || operation.at(0)==68)
	{
		double quo = a / b;
		cout<<"The quotient of the two values is "<<quo<<".\n";
	}
	
}