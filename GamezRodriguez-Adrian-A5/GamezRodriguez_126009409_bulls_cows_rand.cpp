#include <vector>
#include <stdexcept>
#include <iostream>
#include <ctime>
#include "std_lib_facilities.h"

using namespace std;

int numofcows(vector<int> u, vector<int> v) // Returns the number of "cows" for two vectors.
{
	int cows = 0;
	if(u.size()>5 || v.size()>5 ) 
	{
		throw runtime_error("in cows(), wrong vector size."); //checks for input size 
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
		throw runtime_error("in bulls(), wrong vector size."); // pre-requisite
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
		throw runtime_error(" wrong vector size."); // pre-requisite
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
	int guess_element = 0;
	for(int i=0;i<5;++i)
	{
		cin >> guess_element;
		if(!cin)
		{
			throw runtime_error("Invalid input");			//exception for invalid input
		}
		u.push_back(guess_element);
	}
	if(u.size()>5 || u.size()<5 ) 
	{
		throw runtime_error("wrong vector size."); // pre-requisite
	}
	return u;
}

vector<int> rand_ans()
{
	srand(time(0));
	vector<int> ans;
	int random = 0;
	random = randint(10);
	ans.push_back(random);
	bool repeatOfnum = false;
	do
	{
		random = randint(9);
		repeatOfnum = false;
		for( int j=0; j<ans.size(); ++j)
		{
			if(random==ans[j])
			{
				repeatOfnum = true;
			}
		}
		if(!repeatOfnum)
		{
			ans.push_back(random);
			repeatOfnum = false;
		}
	} while(ans.size()<5);
	return ans;
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
		bool noWinYet = true;
		int keep_going = 1;
		int numofGuess=0;
		do			//  loop to repeat the game
		{ 
			int num_guesses = 0;
			noWinYet = true;
			vector<int> ans;
			ans = rand_ans();
			do // loop to repeat prompts for guess.
			{ 
				cout << "Enter your guess (interger seperated by spaces and followed by 'Enter': ";
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
			cout << "\nKeep Playing? Enter 1 for yes or 0 for no: ";
			cin >> keep_going;
			if(keep_going==0)
			{
				break;
			}
		}while(keep_going);
		return 0;
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
