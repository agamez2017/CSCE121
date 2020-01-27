#include <iostream>
using namespace std;
/*
Makes a copy of an array of char in the heap
*/
char* strdup(const char* s)
{
	int size=0;
	for(int i=0;s[i];i++)
	{
		size++;
	}
	char* p =new char[size];
	for(int i=0;s[i]; i++)
	{
		*(p+i)=*(s+i);
	}
	return p;
}
void print_array_of_char(char* s)//function to print
{
	for(int i=0;s[i]; i++)
	{
		cout<<*(s+i);
	}
	cout<<endl;
}
int main()
{
	char string[] = "Hello, World";
	cout<<string<<endl;
	char* s=string;
	char* p = strdup(s); 
	print_array_of_char(p);
}