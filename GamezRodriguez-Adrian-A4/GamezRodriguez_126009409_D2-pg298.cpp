#include <iostream>
#include "std_lib_facilities.h"
/*
Bonus questions:
1. g++ file1.cpp space file2.cpp, it takes to source code files and makes a single execution code 
2. extern int works by declaring a global variable that can be accessed by any other file
3. namespace works by declaring a region that provide the scope of identifiers
4. pass-by-value to pass small objects and makes a copy of the object 
	pass-by-const-reference to pass large objects that you don’t need to modify. 
		pass-by-reference actually changes the actual argument of the paramater.
*/
using namespace std;

void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a=b;
	b=temp;
}
void swap_r(int& a, int& b )
{
	int temp;
	temp = a;
	a=b;
	b=temp;
}
/*void swap_cr(const int& a, const int& b)  //function does not compile because its defintion is works against the constant variables.
{
	int temp;
	temp = a;
	a=b;
	b=temp;
}*/
int main()
{
	int x = 7;
    int y = 9;
    swap_v(x,y);
    cout << "swap_v(x,y) = " << x << " " << y << endl;		//outputs 7, 9 bc the function does not change the inputs
    swap_r(x,y);
    cout << "swap_r(x,y) = " << x << " " << y << endl;		//outputs 9,7 bc the funtion is pass by reference which changes the adress of the inputs
//    swap_cr(x,y); 										//does not work because function does not compile
//    cout << "swap_cr(x,y) = " << x << " " << y << endl;
    swap_v(7,9);
    cout << "swap_v(9,7) = " << x << " " << y << endl;		//outputs 7 and 9 and does not change actual variables x and y
//swap_r(7,9);												//does not compile bc the input is constant and not a variable with an address
//  cout << "swap_r(7,9) = " << x << " " << y << endl;
//    swap_cr(7,9);											//Does not compile because function does not compile
//    cout << "swap_cr(7,9) = " << x << " " << y << endl;
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx,dy);
    cout << "swap_v(dx,dy) = " << dx << " " << dy << endl;	//compiles 
//    swap_r(dx,dy);											//does not compile bc
//    cout << "swap_r(dx,dy) = " << dx << " " << dy << endl;
//    swap_cr(dx,dy);											//Does not compile because of function
//    cout << "swap_cr(dx,dy) = " << dx << " " << dy << endl;
    swap_v(7.7,9.9);											//compiles bc it
    cout << "swap_v(7.7,9.9) = " << dx << " " << dy << endl;
//    swap_r(7.7,9.9);												////does not compile bc the input is int and not a variable with an address
//    cout << "swap_r(7.7,9.9) = " << dx << " " << dy << endl;
//    swap_cr(7.7,9.9);												//Does not compile because of function
//    cout << "swap_cr(7.7,9.9) = " << dx << " " << dy << endl;
}