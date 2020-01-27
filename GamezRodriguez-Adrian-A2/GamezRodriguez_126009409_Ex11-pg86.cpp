#include <iostream>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h"
using namespace std;

int main()
{
int pen;
int nick;
int dim;
int qua;
int half;
int dol;
cout<<"How many pennies do you have?\n";
cin>>pen;
cout<<"How many nickles do you have?\n";
cin>>nick;
cout<<"How many dimes do you have?\n";
cin>>dim;
cout<<"How many quarters do you have?\n";
cin>>qua;
cout<<"How many half dollars coins do you have?\n";
cin>>half;
cout<<"How many one-dollar coins do you have?\n";
cin>>dol;
if (pen ==1)
{
cout<<"You have "<<pen<<" penny.\n";
}
else
	cout<<"You have "<<pen<<" pennies.\n";
if (nick ==1)
{
	cout<<"You have "<<nick<<" nickle.\n";
}
else
	cout<<"You have "<<nick<<" nickles.\n";
if(dim==1)
{
	cout<<"You have "<<dim<<" dime.\n";
}
else 
	cout<<"You have "<<dim<<" dimes.\n";
if(qua==1)
{
	cout<<"You have "<<qua<<" quarter.\n";
}
else 
	cout<<"You have "<<qua<<" quarters.\n";
if(half==1)
{
	cout<<"You have "<<half<<" half dollar coin.\n";
}
else
	cout<<"You have "<<half<<" half dollars coins.\n";
if (dol ==1)
{
	cout<<"You have "<<dol<<" one-dollar coin.\n";
}
else
	cout<<"You have "<<dol<<" one-dollar coins.\n";

double sum = ((pen*.01)+(dim*.1)+(nick*0.05)+(qua*.25)+(half*0.50)+(dol*1));
cout<<"The value of all your coins is $"<<sum<<".\n";
}
