#include <iostream>
using namespace std;
/*
Copied class and main code from the book.
Question 12:
We have two find() functions because the second one serves to find a god in a constant list of gods.
*/
class Link 
{
	public:
	string value;
	Link(const string& v, Link* p = nullptr, Link* s = nullptr): value{v}, prev{p}, succ{s} { };
	Link* insert(Link* n); // insert n before this object
	Link* add(Link* n); // insert n after this object
	Link* erase(); // remove this object from list
	Link* find(const string& s); // find s in list
	const Link* find(const string& s) const; // find s in const list (see §18.5.1)
	Link* advance(int n); // move n positions in list
	Link* next() const { return succ; };
	Link* previous() const { return prev; };
	private:
	Link* prev;
	Link* succ;
};
Link* Link::insert(Link* n) // insert n before this object; return n
{
	if(n==nullptr)//if you insert nothing then just return the this object
	{
		return this;
	}
	if(this==nullptr)//if there is nothing before you are trying to insert n obejct then just n object is the beginning
	{
		return n;
	}
	n -> succ = this; // this object comes after n
	if(prev)
	{		
		prev -> succ = n;//if there's a prev object then the prev's succ becomes n object
	}
	n -> prev = prev; // this object’s predecessor becomes n’s predecessor
	prev = n; // n becomes this object’s predecessor
	return n;
}
Link* Link::add(Link* n)//insert n after this object 
{
	if(n==0)
	{
		return this;
	}
    if(this==0)
	{
		return n;
	}
    n -> prev = this;//n's previous becomes this
    if(succ)
	{
		succ -> prev = n;
	}
    n -> succ = succ;
    succ = n;
    return n;
}
Link* Link::erase()//remove object from the list
{
	if(this==0)
	{
		return 0;
	}
    if(succ) 
	{
		succ -> prev = prev;
	}
    if(prev)
	{
		prev -> succ = succ;
	}
    return succ;
}
 Link* Link::find(const string& s) 
{
    Link* p = this;
    while (p) 
	{
        if(p -> value==s)
		{
			return p;
		}
        p = p -> succ;
    }
    return 0;
}
const Link* Link::find(const string& s) const
{
	const Link* p = this;
    while(p)
	{
        if (p -> value==s)
		{
			return p;
		}
        p = p->succ;
    }
    return 0;
}
Link* Link::advance(int n) // move n positions in list, return nullptr for “not found”, positive n moves forward, negative backward
{
	const Link* p = this ;
	if(p==nullptr)
	{
		return nullptr;
	}
	if(0<n) 
	{
		while(n=n-1) 
		{
			if(p -> succ == nullptr)
			{
				return nullptr;
			}
			p = p -> succ;
		}
	}
	else if(n<0) 
	{
		while(n=n+1)
		{
			if(p -> prev == nullptr)
			{
				return nullptr;
			}
			p = p -> prev;
		}
	}
	return  this;
} 
void print_all(Link* p)
{
	cout << "{ ";
	while(p)
	{
		cout << p -> value;
		if(p = p -> next())
		{
			cout << ", ";
		}
	}
 cout << " }";
}
int main()
{

	Link* norse_gods = new Link{"Thor"};
	norse_gods = norse_gods -> insert(new Link{"Odin"});
	norse_gods = norse_gods -> insert(new Link{"Zeus"});
	norse_gods = norse_gods -> insert(new Link{"Freia"});
	Link* greek_gods = new Link{"Hera"};
	greek_gods = greek_gods -> insert(new Link{"Athena"});
	greek_gods = greek_gods -> insert(new Link{"Mars"});
	greek_gods = greek_gods -> insert(new Link{"Poseidon"});
	
	Link* p = greek_gods -> find("Mars");
	if(p)
	{
		p -> value = "Ares";
	}
	Link* p2 = norse_gods -> find("Zeus");
	if(p2)
	{
		if(p2==norse_gods)
		{
			norse_gods = p2 -> next();
		}
		p2 -> erase();
		greek_gods = greek_gods -> insert(p2);
	}
	
	print_all(norse_gods);
	cout<<"\n";
	print_all(greek_gods);
	cout<<"\n";

}