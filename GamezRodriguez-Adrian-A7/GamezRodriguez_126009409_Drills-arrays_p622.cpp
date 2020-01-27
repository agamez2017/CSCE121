#include "std_lib_facilities.h"
#include <iostream>
using namespace std;
//function to initialize array values
void initialize_array (int * a, int n) 
{
    for (int i = 0; i < n; ++i)
	{
		a[i] = 100+i;
	}
};
//function to initialize vector values
void initialize_vector (vector<int>& u, int n)
{
	for(int i= 0 ; i<n; i++)
	{
		u[i]= 100+i;
	}
	
}
//drill4
void print_array10(ostream& os, int* a)
{
	for(int *i = a; i<a+10;i++)
	{
	 os<<*i<<" ";
	}
	cout<<endl;
}
//drill 7
void print_array(ostream& os, int* a, int n)
{
	for(int* i=a;i<a+n;i++)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
}
//drill 10
void print_vector(ostream & os, vector<int> & v) 
{
    for (int i = 0; i < v.size(); i++)
	{
		os << v[i] << " ";
	}
		os << endl;
}
int main()
{
	//drill 1
	int * a= new int[10];
	for(int i=0; i<10;i++)//initializing array values
	{
		a[i]= i;
	}
	//drill 2
	for(int i=0; i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	//drill 3
	delete []a;
	//drill 5
	int * b = new int[10];
    initialize_array(b,10);//initializes array values starting from 100;
    print_array10(cout,b);
	//drill 6
    int * c = new int[11];
    initialize_array(c,11);//initializes array values starting from 100;
    print_array(cout,c,11);//uses funtion to print array of any size
	//drill 8
    int * d = new int[20];
    initialize_array(d,20);//initializes array values starting from 100;
    print_array(cout,d,20);//prints array of any size
	//drill 9
	delete [] b;
	delete [] c;
	delete [] d;
	//drill 10
	//drill 10-5
	vector<int> v(10);
	initialize_vector(v,10);
	print_vector(cout,v);
	//drill 10-6
	vector<int> u(11);
	initialize_vector(u,11);
	print_vector(cout,u);
	//drill 10-8
	vector<int> z(20);
	initialize_vector(z,20);
	print_vector(cout,z);
}