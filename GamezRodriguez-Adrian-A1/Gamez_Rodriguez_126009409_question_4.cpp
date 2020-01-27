#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include "std_lib_facilities.h"
 using namespace std;
int main()
{
double q1;
double q2;
double q3;
double exam1;
double exam2;
double assign1;
double assign2;
double assign3;
double assign4;
double totalscore;
cout<< "Enter points for the 3 quizzes with a space between each score.(followed by enter):\n";
cin>> q1>>q2>>q3;
cout<<"Enter points for the 2 exams:\n";
cin>>exam1>>exam2;
cout<<"Enter points for the 4 assignment:\n";
cin>>assign1>>assign2>>assign3>>assign4;
double quizAverage = (q1+q2+q3)/3;
double examAverage = (exam1+exam2)/2;
double assignAverage = (assign1+assign2+assign3+assign4)/4;
totalscore= (quizAverage*1.2)+(examAverage*.6)+(assignAverage*.28);
cout<<"Your total score is "<< setprecision(4)<<totalscore<<"%\n";
}