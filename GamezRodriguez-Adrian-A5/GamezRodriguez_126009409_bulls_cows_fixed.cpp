#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

int numofcows(vector<int> u, vector<int> v)// Returns the number of "cows" for two vectors
{
	int cows = 0;
	if(u.size()>5 || v.size()>5 ) 
	{
		throw runtime_error("in cows(), wrong vector size.");
	}
	for(int i=0; i<u.size(); ++i)
	{
		for(int j=0; j<v.size(); ++j)
		{
			if(u[i]==v[j] && j!=i)
			{
				++cows;
			}
		}
	}
	return cows;
}

int numofbulls(vector<int> u, vector<int> v)// Returns the number of "bulls" for two vectors
{
	int bulls = 0;
	if(u.size()>5 || v.size()>5 ) 
	{
		throw runtime_error("in bulls(), wrong vector size."); 
	}
	for(int i=0; i<u.size(); ++i)
	{
		if (u[i]==v[i])
		{
			++bulls;
		}
	}
	return bulls;
}

bool check(const vector<int>& u) // Checks the vector for repetition and range of numbers.
{
	if(u.size()>5 || u.size()<0 ) 
	{
		return false;
	}
	for(int i=0; i<u.size(); ++i)
	{
		if(u[i]<0||u[i]>9)
		{
			return false;
		}
		for(int j=4; j>i; --j)
		{
			if(u[i]==u[j])
			{				
				return false;
			}
		}
	}
	return true;
}

vector<int> get_guess()
{
	vector<int> u;
	int guess_element;
	for(int i=0;i<5;++i)
	{
		cin >> guess_element;
		if(!cin)
		{
			throw runtime_error("Invalid input");			//exception for invalid input
		}
		u.push_back(guess_element);
	}
	return u;
}

void print_Vec(const vector<int>& v)
{
	for(int i=0; i<v.size(); ++i)
	{
		cout << v[i];
	}
}

int main()
{
	try
	{
		vector<int> ans = {6,5,1,3,0};
		char c;
		cout<<"Welcome to the Bulls and Cows Game!\n";
		cout<<"For grading purposes: Enter 'y' to get code now then run again to check otherwise just enter any character to continue\n";
		cin>>c;
		if(c == 'y')
		{
			print_Vec(ans);
		}
		else
		{
		bool noWinYet = true;
		int num_guesses = 0;
		noWinYet = true;
		do // A loop to repeat prompts for guess.
			{ 
				cout << "Enter your guess (interger seperated by spaces and followed by 'Enter': \n";
				vector<int> guess = get_guess();
				if(check(guess))
				{
					++num_guesses;
					cout <<"Bulls: "<< numofbulls(guess,ans)<< " Cows: " << numofcows(guess,ans)<< endl;
				}
				else
				{
					cout << "Invalid Input. Please input 5 unique digits from 0 to 9 inclusive seperated by spaces." << endl;
				}
				if ( numofbulls(guess,ans)== 5 )
				{
					cout << "\nNumber of tries to win: " << num_guesses << "\nThe code was ";
					print_Vec(ans);
					cout << endl;
					num_guesses = 0;
					noWinYet = false;
				}
			}while(noWinYet);
		}
	}
	catch(exception& e)
	{
		cerr << endl << "Error: " << e.what() << endl;
		return 1;
	}
	catch(...)
	{
		cerr << endl << "Unknown exception!" << endl;
		return 2;
	}
}
