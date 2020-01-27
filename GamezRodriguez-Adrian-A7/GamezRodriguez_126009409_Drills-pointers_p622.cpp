#include <iostream>
#include "std_lib_facilities.h"
using namespace std;
void print_array(ostream& os, int* a, int n)
{
	for(int* i=a;i<a+n;i++)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
}
void print_vector(vector<int>& u)
{
	for(int i =0; i<u.size();i++)
	{
		cout<<u[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	//drill 1
	int *p1 = new int(7);
	//drill 2
	cout<<"p1 : "<<p1<<endl;
	cout<<"Points to : "<<*p1<<endl;
	//drill 3
	int *p2 = new int[7];
	int n=1;
	for(int i=0; i<7;i++)//initilizing array values
	{
		p2[i]=n;
		n= n*2;
	}
	//drill 4
	cout<<"p2: "<<p2<<endl;
	print_array(cout, p2, 7);
	//drill 5
	int* p3 = p2;
	//drill 6
	p2 = p1;
	//drill 7
	p1 = p3;
	//drill 8 
	cout<<"p1: "<<p1<<endl;
	print_array(cout, p1,7);
	cout<<"p2: "<<p2<<endl;
	cout<<*p2<<endl;
	//drill 9
	delete [] p1;
	delete  p2;
	//drill 10
	cout<<"Using Arrays :\n";
	int* a = new int[10];
	p1 =a;
	n=1;
	for(int i=0; i<10;i++)//initilizing array values
	{
		p1[i]=n;
		n=n*2;
	}
	print_array(cout,p1,10);
	//drill 11
	int* b = new int[10];
	 p2 =b;
	//drill 12
	for(int i=0; i<10; ++i)//copying the first array of size 10 into the second array of size 20
	{
		p2[i] =p1[i];
	}
	print_array(cout,p2,10);
	//drill 13
	cout<<"Using vectors :\n";
	vector<int> u(10);
	n=1;
	for(int i=0; i<10;i++)//initilizing vector of size 10 
	{
		u[i] = n;
		n=n*2;
	}
	print_vector(u);
	vector<int> v(10);
	for(int i =0; i<10; i++)//copying vector of size 10 into a vector of size 20
	{
		v[i]=u[i];
	}
	print_vector(v);
}