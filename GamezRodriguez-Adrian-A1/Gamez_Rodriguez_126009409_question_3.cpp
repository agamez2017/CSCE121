#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include "std_lib_facilities.h"
 using namespace std;
int main()
{
	string first_name; 
	string last_name;
	string sec;
	string Ta_first_name;
	string Ta_last_name;
	string Ptfirst_name;
	string Ptlast_name;
	string Pt2first_name;
	string Pt2last_name;
	cout<<"Enter your first name, last name and section number with a 'space' in between each.(followed by enter):\n";
	cin>>first_name>> last_name>>sec;
	cout<<"Who is your TA?\n";
	cin>> Ta_first_name>>Ta_last_name;
	cout<<"Who are your PTs?\n";
	cin>> Ptfirst_name>>Ptlast_name>>Pt2first_name>>Pt2last_name;
	cout<<last_name<<", "<<first_name<<": "<<sec <<"\n";
	cout<<"TA: "<<Ta_last_name<<", "<<Ta_first_name<<"\n";
	cout<<"PT: "<<Ptlast_name<<", "<<Ptfirst_name<<"\n";
	cout<<"PT: "<<Pt2last_name<<", "<<Pt2first_name<<"\n";
}