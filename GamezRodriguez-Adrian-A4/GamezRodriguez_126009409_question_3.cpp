#include <iostream>
#include <stdexcept>
struct pair
{
	int first;
	int second;
	void print()
	{
		std::cout<<"("<<first<<","<<second<<")"<<std::endl;
	}
};
pair make_pair(int x, int y)
{
	return {x, y};	
}
pair fib(int k)
{
	if (k<0)
	{
		throw std::invalid_argument("Received negative value");
	}
	if(k<= 1)
	{
		return make_pair(k ,0);
	}
	else
	{
		struct pair prev;
		prev  = fib(k-1);
		return make_pair(prev.first+prev.second, prev.first);
	}
}

int main(){
	int k;
	std::cout<<"Enter an interger k: (followed by enter)"<<std::endl;
	std::cin>>k;
	fib(k).print();
	std::cout<<"The kth fibonacci is : "<<fib(k).second<<std::endl;
}