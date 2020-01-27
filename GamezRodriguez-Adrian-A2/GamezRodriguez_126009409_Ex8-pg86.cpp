#include <iostream>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h"
using namespace std;

int main()
{
	int a;
	cout<<"Enter an Integer Value: (followed by enter)\n";
	cin>>a;
	if ((a%2)==0)
	{
		cout<<"The value "<<a<<" is an even number.\n";
	}
	else
		cout<<"The value "<<a<<" is an odd number.\n";
	
}
