#include <iostream>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h"
using namespace std;

int main()
{
	int a;
	int b;
	int c;
	vector<int>nums;
	cout<<"Enter three integers: (followed by Enter)\n";
	cin>>a>>b>>c;
	nums.push_back(a);
	nums.push_back(b);
	nums.push_back(c);
	/*for (int i=0;i<nums.size()-1;++i)
	{
	if(nums[i+1]<=nums[i])
	{
		int temp = nums[i];
		nums[i]=nums[i+1];
		nums[i+1]=temp;	
	}
	}*/
	sort(nums);
	cout<<nums[0]<<", "<<nums[1]<<", "<<nums[2]<<"\n";
	cout<<"Excersice 7 begins.\n";
	string s1;
	string s2;
	string s3;
	cout<<"Enter three strings: (followed by Enter)\n";
	cin>>s1>>s2>>s3;
	vector<string> words;
	words.push_back(s1);
	words.push_back(s2);
	words.push_back(s3);
	/*for (int j=0;j<words.size()-1;++j)
	{
	if(words[j+1]<=words[j])
	{
		string temp = words[j];
		words[j]=words[j+1];
		words[j+1]=temp;
	}
	}*/
	sort(words);
	cout<<words[0]<<", "<<words[1]<<", "<<words[2];
}
