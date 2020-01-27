#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

int main()
{
	double dis;
	double root1;
	double root2;
	double a; 
	double b;
	double c;
	cout<<"Enter a, b, c of quadratic function (followed by enter)\n";
	cin>>a>>b>>c;
	if(a==0)
	{
		if(a==0 && b ==0 && c==0)
		{
			cout<<"Infinte number of roots.\n";
		}
		if(a==0 && b==0 && (c > 0 || c<0))
		{
			cout<<"No solutions.\n";
		}
		if(a ==0 && (b>0 || b<0) && (c>0 ||c<0))
		{
			root1= -c/b;
			cout<<"Linear equation! Root is "<<root1<<endl;
		}
	}
	else 
	{
		dis = (b*b)-(4*a*c);
		if(dis>0)
		{
			root1 = (-b + sqrt(dis) )/ (2*a);
			root2 = (-b - sqrt(dis))/(2*a);
			cout<<"Roots are: "<<root1<<" and "<<root2<<".\n";
		}
		if(dis == 0)
		{
			root1 = -b /(2*a);
			cout<<"Roots are equal to "<<root1<<".\n";
		}
		if(dis < 0)
		{
			cout<<"Roots are complex. My formula cannot find complex roots.\n"<<endl;
		}
	}
}