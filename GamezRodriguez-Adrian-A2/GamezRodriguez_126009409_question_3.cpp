#include <iostream>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h"
using namespace std;
//Adrian Gamez-Rodriguez
//Compute the sequence of fibonacci numbers and how many numbers fit in an int long and long long
int main()
{
	int f1 = 1;
	int f2 = 2;
	int fibNum;
	vector<int> fib = {1,2}; //creates a vector with the two starting fibonacci numbers
	for(int i = 2;i<=45;++i)
	{
		fibNum=fib[(i-2)]+fib[(i-1)];
		if (fibNum>0)
		{
		fib.push_back(fibNum);
		}
		
	}
	cout<<"The number of fibonacci numbers that can fit in an signed int is: "<<fib.size()<<".\n";
	cout<<"The largest fibonacci number that can fit in an int is: "<<fib[fib.size()-1]<<".\n";

	//-------------------------------------------------------------------------------------
	long f_1=1;
	long f_2=2;
	long count_2=1;
	long fibLong;
	while (fibLong>=0)//found a better way to implement the formula by using the while loop
	{
		fibLong = f_1+f_2;
		f_1=f_2;
		f_2=fibLong;
		count_2++;
	}
	cout<<"The number of fibonacci numbers that can fit in a long is: "<<count_2<<".\n";
	cout<<"The largest fibonacci number that can fit in a long is: "<<f_1<<".\n";
	//-----------------------------------------------------------------------------------------
	long long int F1 =1;
	long long int F2 =2;
	long long int count_3=1;
	long long int fibLongLong;
	while (fibLongLong>=0)
	{
		fibLongLong= F1+F2;
		F1=F2;
		F2=fibLongLong;
		count_3++;
	}
	cout<<"The number of fibonacci numbers that can fit in a long long is: "<<count_3<<".\n";
	cout<<"The largest fibonacci number that can fit in a long long is: "<<F1<<".\n";
}