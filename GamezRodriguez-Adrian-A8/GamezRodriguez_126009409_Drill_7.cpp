#include "std_lib_facilities.h"
using namespace std;
class B2
{
	public:
	virtual void pvf() =0;
};
class D21: public B2
{
	public:
	D21(string arg): s(arg) {};
	void pvf() { cout<<s<<endl;}
	private:
	string s;
};
class D22: public B2
{
	public:
	D22(int num): i(num) {};
	void pvf() {cout<<i<<endl;}
	private:
	int i;
};
void f(B2& a)
{
	a.pvf();
}
int main()
{
	D21 d21("hello");
	D22 d22(10);
	f(d21);//reference to base class from D21 class 
	f(d22);//reference to base class from D22 class
	//since its a pure virtual function and is overrided in both derived classes rhe output should be a string 
	//for D21 class and a int for D22 class
}