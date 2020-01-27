#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include "std_lib_facilities.h"
 using namespace std;
int main()
{
	cout<<"Enter the name to the person you want to write to (followed by 'enter'):\n";
	string first_name;
	cin>>first_name;
	cout<<"Drill 1 begins:\n";
	cout<< "Dear " << first_name << ",\n";
	cout<<"Drill 2 begins:\n";
	cout<<"	How are you? I am fine. I miss you. \nWe haven't seen each since highschool its been a long time.\n";
	cout<<"I'm really glad I wrote you this letter. I just wanted to keep in touch.\n";
	cout<<"Drill 3	begins:\n";
	cout<< "Enter the name of another friend (followed by enter):\n";
	string friend_name;
	cin >> friend_name;
	cout<< "Have you seen "<<friend_name<<" lately?\n";
	cout<<"Drill 4 begins:\n";
	char friend_sex = 0;
	cout<<"Enter m for male or f for female (followed by 'enter'):\n";
	cin >> friend_sex;
	if (friend_sex == 109)
	{
		cout<<"If you see "<< friend_name<<" please ask him to call me.\n";
	}
	if (friend_sex == 102)
	{
		cout<<"If you see "<<friend_name<<" please ask her to call me.\n";
	}
	cout<<"Drill 5 begins:\n";
	cout<< "Enter age of recipient (followed by enter):\n";
	int age =0;
	cin>>age;
	cout<< "I hear you just had a birthday and you are "<<age<<" years old.\n";
	cout<<"Drill 6 begins:\n";
	if (age <= 0 || age >=110)
	{
		simple_error(" You're kidding!\n");
	}
	if (age < 12)
	{
		cout<<"Next year you will be "<< (age+1)<<".\n";
	}
	if (age == 17 )
	{
		cout<<"Next year you will be able to vote.\n";
	}
	if (age > 70 )
	{
		cout<<"I hope you are enjoying retirement.\n";
	}
	cout<<"Drill 7 begins:\n";
	cout<<"Yours sincerely, \n";
	cout<<"______________________\n";
	cout<<"______________________\n";
	cout<<"Adrian Gamez-Rodriguez\n";
	
	
	return 0;
}