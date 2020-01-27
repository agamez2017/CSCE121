#include <iostream>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h"
using namespace std;
//Adrian Gamez-Rodriguez
//UIN: 126009409
//Trying to solve question 9. Turn all inputs into integers between 0 and 4.
int main()
{
	cout<<"Enter a spelled out number between 0 and 4: (followed by enter)\n";
	string s;
	cin>>s;
	if (s.at(0)== 90 || s.at(0) == 122)
	{
		cout<<"The numerical digit is 0.\n";
	}
	else if(s.at(0)== 79 || s.at(0) == 111)
	{
		cout<<"The numerical digit is 1.\n";
	}
	else if(s.at(0) == 70 || s.at(0) == 102)
	{
		cout<<"The numerical digit is 4.\n";
	}
	else if(s.at(0) == 84 || s.at(0) == 116)
	{
		if(s.at(1) == 87 || s.at(1) == 119)
		{
			cout<<"The numerical digit is 2.\n";
		}
		else
			cout<<"The numerical digit is 3.\n"; 	
	}
	else
		cout<<"Not a number I know. Sorry. \n";
	
}