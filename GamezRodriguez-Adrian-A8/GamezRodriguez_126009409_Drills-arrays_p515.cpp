#include "std_lib_facilities.h"
using namespace std;
class B1
{
	public:
	virtual void vf()
	{
		cout<<"B1::vf()\n";
	};
	void f()
	{
		cout<<"B1::f()\n";
	};
};
class D1: public B1
{
	public:
	void vf()
	{
		cout<<"D1::vf()\n";
	}
};

int main()
{
	//Drill 1 Define Class B1 w/ virtual function , and non-virtual function
	cout<<"Drill 1\n";
	B1 object;
	object.vf();//will call vf() in B1
	object.f();//will f() in B1
	//Drill 2 Derive Class D1 and override vf() make object, call vf() and f()
	cout<<"Drill 2\n";
	D1 object2;
	object2.vf();//will call vf() in D1 because its a virutal function and overwritten in D1
	object2.f();//will call f() in B1 because it is a non virtual function 
	//Drill 3
	cout<<"Drill 3\n";
	B1& i = object2; //reference to B1 class and initilized to D1 object
	i.vf(); //will call the vf() in D1 again because its a virtual function
	i.f(); // will call f() in B1 
	
}