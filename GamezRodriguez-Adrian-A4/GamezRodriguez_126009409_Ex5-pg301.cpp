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
void printVec(const vector<int>& v)
{
	for(int i = 0;i<v.size();++i)
	{
		cout<<v[i]<<" ";
	}
	cout << endl;
}
void rev1(const vector<int>& v, vector<int>& u)
{
	for(int i = 0;i<v.size();++i)
	{
		u.push_back(v[v.size()-1-i]);
	}
}
void rev2(vector<int>& v)
{
	int n = v.size();
    for (int i = 0; i < n/2; ++i) {
        int k = v[i];
        v[i] = v[n-1-i];
        v[n-1-i] = k;
    }
	
}
int main()
{
	try{
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
	else
	{
	vector<int> z;		//initializes new vector z
	rev1(v,z);			//sets the vector z to the reverse vector of input vector v by pass by const reference
	cout<<"rev1(v) makes a new vector: \n";
	printVec(z);
	rev2(v);			//actually changes the input vector and does not need another one
	cout<<"rev2(v) changes the input vector to (not using an aditional vector, thus chaging the input vector): \n";
	printVec(v);
	}
	}
	catch(exception& error)
	{
		cout<<error.what();
	}
}
