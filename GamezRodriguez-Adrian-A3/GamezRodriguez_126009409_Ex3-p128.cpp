#include <iostream>
#include "std_lib_facilities.h"
class InvalidInput { };
using namespace std;
int main()
{
	cout<<"Enter distances (followed by a semicolon and enter):\n";
	vector<double> dists; 
	for(double dis; cin>>dis;)
	{
		dists.push_back(dis);
	}
	sort(dists);
	double sum =0;
	double mean = 0;
	if (dists.size() == 0)
	{
		simple_error("No input detected! Cannot calculate!");
	}
	for(int i = 0;i<dists.size();++i)
	{
		sum += dists[i];
	}
	mean = sum/dists.size();
	cout<<"The sum of distances is "<<sum<<'\n';
	cout<<"The mean of all distances is "<<mean<<'\n';
	cout<<"The smallest distance is "<<dists[0]<<'\n';
	cout<<"The largest distance is "<<dists[dists.size()-1]<<'\n';
	
}