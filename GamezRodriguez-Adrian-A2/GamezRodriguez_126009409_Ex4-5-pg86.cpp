#include <iostream>
//Adrian Gamez-Rodriguez 
//UIN: 126009409
//Solving question 4 and 5. 
using namespace std;
int main()
{
 int val1;
 int val2;
 cout<< "Enter two integer values: (followed by enter)\n";
 cin>>val1 >> val2;
 int sum = val1 +val2 ;
 int diff = abs(val1-val2);
 int prod = (val1 * val2);
 int ratio = abs(val1/val2);
 if (val1>val2)
 {
	 cout<<"Larger value: "<< val1<<"\n";
	 cout<<"Smaller value: "<< val2<<"\n";
	
 }
 else if (val1==val2)
 {
	 cout<< "Two vallues are equal!\n";
	 
 }
 else
 {
	 cout<<"Larger value: "<< val2<<"\n";
	 cout<<"Smaller value: "<< val1<<"\n";
	 
 }
	cout<<"Sum is: "<<sum<<"\n";
	cout<<"Difference is: "<<diff<<"\n";
	cout<<"Product is: "<<prod<<"\n";
	cout<<"Ratio of number 1 / number 2: "<<ratio<<"\n";
	//excersice 5 begins
	cout<<"Exercise 5 begins.\n";
	double val3;
 double val4;
 cout<< "Enter two floating point values: (followed by enter)\n";
 cin>>val3 >> val4;
 double sum2 = val3 +val4 ;
 double diff2 = abs(val3-val4);
 double prod2 = (val3 * val4);
 double ratio2 = abs(val3/val4);
 if (val3>val4)
 {
	 cout<<"Larger value: "<< val3<<"\n";
	 cout<<"Smaller value: "<< val4<<"\n";
	
 }
 else if (val3==val4)
 {
	 cout<< "Two vallues are equal!\n";
	 
 }
 else
 {
	 cout<<"Larger value: "<< val4<<"\n";
	 cout<<"Smaller value: "<< val3<<"\n";
	 
 }
	cout<<"Sum is: "<<sum2<<"\n";
	cout<<"Difference is: "<<diff2<<"\n";
	cout<<"Product is: "<<prod2<<"\n";
	cout<<"Ratio of number 1 / number 2: "<<ratio2<<"\n";
}