#include <iostream>
using namespace std;
/*
Takes a array of char including whitespaces and turns them all lower case.
Just change the char[] in line 35 to test the output
*/
bool isUpper(char chr)
{
	if(chr >= 'A' && chr<='Z')
	{
		return true;
	}
	return false;
}
void to_lower(char* s)
{
	for(int i=0; s[i];i++)
	{
		if(isUpper(*(s+i))==1)
		{
			*(s+i) = *(s+i) +32;
		}
	}
}
void print_array_of_char(char* s)
{
	for(int i =0; s[i]; i++)
	{
		cout<<s[i];
	}
	cout<<endl;
}
int main()
{
	cout<<"Original string: \n";
	char string[]="Hello, World!";
	cout<<string<<endl;
	char* p = string;
	to_lower(p);
	cout<<"Corresponding lower case output: \n";
	print_array_of_char(p);
}