#include <iostream>
#include <vector>
#include "std_lib_facilities.h"
using namespace std;
class Name_pairs
{
	public:
	void print();
	void read_names();
	void read_ages();
	void sort_name();
	const vector<string>& get_name() const { return name; }
 	const vector<double>& get_age() const { return age; }
	private:
	vector<string> name;
	vector<double> age;
};
void Name_pairs::read_names()
{
	cout<<"Please Enter names and enter 'stop' to stop followed by enter: \n";
	string s;
	while(cin>>s && s!= "stop")
	{
			name.push_back(s);
	}
}
void Name_pairs::read_ages()
{
	cout<<"Enter corresponding ages to names: \n";
	for(int i=0; i<name.size();++i)
	{
		cout<<"Enter age of : "<<name[i]<<": ";
		double ages;
		cin>> ages;
		age.push_back(ages);
	}
}
/*void Name_pairs::print()
{
	for(int i=0; i<name.size(); ++i)
	{
		cout<<"("<<name[i]<<","<<age[i]<<")"<<endl;
	}
}*/
void Name_pairs::sort_name()
{
  for(int i=0; i<name.size(); ++i)
  {
	  for(int j=0; j<name.size()-i-1; ++j)
	  {
		  if(name[j]>name[j+1])
		  {
			string tmp = name[j];
			name[j]= name[j+1];
			name[j+1]= tmp;
			double agetmp = age[j];
			age[j]=age[j+1];
			age[j+1]=agetmp;
		  }
		  
	  }
  }
}
ostream& operator<<(ostream& os, const Name_pairs& obj)
{
    for(int i = 0; i<obj.get_name().size(); ++i)
	{
        os << '(' << obj.get_name()[i] << ',' << obj.get_age()[i] << ')' << endl;
	}
    return os;
}
bool operator==(const Name_pairs& obj1, const Name_pairs& obj2)
{
    if(obj1.get_name().size()!=obj2.get_name().size() || obj1.get_age().size() != obj2.get_age().size())
	{
        return false;
	}
    for(int i = 0; i<obj1.get_name().size(); ++i) 
	{
        if(obj1.get_name()[i] != obj2.get_name()[i])
		{
            return false;
		}
    }
    for (int i = 0; i<obj1.get_age().size(); ++i) 
	{
        if(obj1.get_age()[i] != obj2.get_age()[i])
		{
            return false;
		}
    }
    return true;
}
bool operator!=(const Name_pairs& obj1, const Name_pairs& obj2)
{
    return !(obj1==obj2);
}
int main()
{
	try
	{
		Name_pairs obj1;
		obj1.read_names();
		obj1.read_ages();
		obj1.sort_name();
		Name_pairs obj2;
		obj2.read_names();
		obj2.read_ages();
		obj2.sort_name(); 
		cout << "First Name_pair object:\n" << obj1;
		cout << "Second Name_pair object:\n" << obj2;
		if(obj1 == obj2)
		{		
			cout << "Same\n";
		}
		if(obj1 != obj2) 
		{
			cout << "Different\n";
		}
	}
	catch (exception& e) 
	{
    cerr << "exception: " << e.what() << endl;
	}
	catch (...) 
	{
    cerr << "exception\n";
	}
}