#include "std_lib_facilities.h"
using namespace std;
/*Explanation of drill 4 is commented below next to function calls
*/
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
	virtual void pvf()=0;//drill 5
};
class D1: public B1
{
	public:
	void vf()
	{
		cout<<"D1::vf()\n";
	}
	void f()//drill 4
	{
		cout<<"D1::f()\n";
	}
	void pvf()
	{
		cout<<"D1::pvf()\n";
	}
};
class D2: public D1//Drill 6
{
	public:
	void pvf()//Drill 6
	{
		cout<<"D2::pvf()\n";
	}
};
int main()
{
	//Drill 4
	//I defined the function f() for D1 class and repeated drills 1-3 
	cout<<"Drill 4\n";
	//cout<<"Object of Class B1\n";
	//B1 b1;
	//b1.vf();
	//b1.f();
	cout<<"Oject of Class D1\n";
	D1 d1;
	d1.vf();
	d1.f();//will call D1 f() beacuse we defined an object of D1 
	cout<<"REFERENCE to B1 initilized with OBject of class D1\n";
	B1& i = d1;
	i.vf();
	i.f();//will call B1 f() since the object is in reference of the base class so it will call B1::f()
	//Drill 5
	cout<<"Drill 5\n";
	cout<<"NOTE: Drill 5 made B1 class abstract, thats why you don't see a B1 object above or below.\n";
	cout<<"Oject of Class D1 with pvf() function\n";
	D1 d12;
    d12.vf();
    d12.f();
    d12.pvf();
	cout<<"REFERENCE to B1 initilized with OBject of class D1\n";
    B1& c = d12;
    c.vf();
    c.f();
    c.pvf();
	//Drill 6
	cout<<"Drill 6\n";
	cout<<"Object of Class D2 derived from D1 with pvf overrided\n";
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();
	
}