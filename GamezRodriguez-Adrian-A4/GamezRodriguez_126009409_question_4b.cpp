#include <iostream>
#include <vector>
#include <exception>
using namespace std;
class MyException :public exception{
	public:
	const char * what() const throw ()
	{
		return " Error! Size of input array is 0.\n";
	}
};
void recurRev(vector<int>& v,int i, int j)
{
	if(i<j)
	{
		int temp;
		temp = v[i];
		v[i]= v[j];
		v[j] = temp;
		recurRev(v, i +1, j-1);
	}
}
void printVec(const vector<int>& v)
{
	for(int i = 0;i<v.size();++i)
	{
		cout<<v[i]<<" ";
	}
	cout << endl;
}
int main()
{
	try
	{
	cout<<"Enter vector of intergers only: (followed by semicolon and enter)"<<endl;
	vector<int> v; 
	for(int val; cin>>val;)
	{
		v.push_back(val);
	}
	if(v.size()==0)
	{
		MyException error;
		throw error;
	}
	int j;
	j= v.size()-1;
	int i;
	i = 0;
	cout<<"The recursive algorithm outputs: "<<endl;
	recurRev(v,i,j);
	printVec(v);
	}
	catch(exception& error){
		cout<<error.what();
	}
}
	
	
	