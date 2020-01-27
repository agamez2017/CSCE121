#include <iostream>
using namespace std;
/*
Same as excerise 11 but only using a singly linked list.
Exception used for the advance function beacause it can only move foward
*/
class Invalid_input{};
struct List;
class Link 
{
	public:
	string value;
	Link(const string& v, Link* s = nullptr): value{v}, succ{s} { };
	Link* insert(List& a,Link* n); // insert n before this object in this a list
	Link* add(Link* n); // insert n after this object
	Link* erase(List& a); // remove this object from a list
	Link* find(const List & a ,const string& s); // find s in list
	const Link* find(const List& a,const string& s) const;// find s in const list (see §18.5.1)
	Link* advance(int n); // move n positions in list
	Link* next() const { return succ; };
	private:
	Link* succ;
};
struct List 
{
	List(): first_link(0){}
	List(Link* p):first_link(p){}
	Link* first_link;
};
Link* Link::insert(List& a, Link* n) // insert n before this object; return n
{
	if(n==nullptr)
	{
		return this;
	}
	if(this==nullptr)
	{
		return n;
	}
	n -> succ = this; // this object comes after n
	if(a.first_link == this)//
	{
		a.first_link =n;
		return n;
	}
	Link* p;
	p=a.first_link;
	while(p -> succ != this)
	{
		p = p->succ;
	}
	p -> succ =n;
	
}
Link* Link::add(Link* n)
{
	if(n==0)
	{
		return this;
	}
    if(this==0)
	{
		return n;
	}
	n -> succ = this -> succ;
    this -> succ = n;
    return n;
}
Link* Link::erase(List& a)
{
	Link* p =a.first_link;
	if(this==0)
	{
		return 0;
	}
	while(p ->succ != this)
	{
		p =p->succ;
	}
	p->succ = this -> succ;
	return succ;

}
 Link* Link::find(const List& a , const string& s) 
{
    Link* p = a.first_link;
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
const Link* Link::find(const List& a, const string& s) const
{
	const Link* p= a.first_link;
	while(p)
	{
		if(p -> value ==s)
		{
			return p;
		}
		p=p ->succ;
	}
	return 0;
}
Link* Link::advance(int n)  // move n positions in list, return nullptr for “not found”, positive n moves forward, negative backward
{
	Link* p = this;
	if(this==nullptr)
	{
		return nullptr;
	}
	if(n >= 0)
	{
		while(n =n-1)
		{
			if(p->succ ==0)
			{
				return nullptr;
			}
			p= p->succ;
		}
	}
	if(n<0)
	{
		throw Invalid_input();
	}
	return p;
}
void print_all(const List& a)
{
	Link* p = a.first_link;
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
	try
	{
	Link* norse_gods = new Link{"Thor"};
	List norse_gods_list(norse_gods);
	norse_gods = norse_gods -> insert(norse_gods_list, new Link{"Odin"});
	norse_gods = norse_gods -> insert(norse_gods_list, new Link{"Zeus"});
	norse_gods = norse_gods -> insert(norse_gods_list, new Link{"Freia"});
	
	
	Link* greek_gods = new Link{"Hera"};
	List greek_gods_list(greek_gods);
	greek_gods = greek_gods -> insert(greek_gods_list, new Link{"Athena"});
	greek_gods = greek_gods -> insert(greek_gods_list, new Link{"Mars"});
	greek_gods = greek_gods -> insert(greek_gods_list, new Link{"Poseidon"});
	
	Link* p = greek_gods -> find(greek_gods_list, "Mars");
	if(p)
	{
		p -> value = "Ares";
	}
	Link* p2 = norse_gods -> find(norse_gods_list, "Zeus");
	if(p2)
	{
		if(p2==norse_gods)
		{
			norse_gods = p2 -> next();
		}
		p2 -> erase(norse_gods_list);
		greek_gods->add(p2);
		greek_gods= greek_gods_list.first_link;
	}
	
	print_all(norse_gods_list);
	cout<<"\n";
	print_all(greek_gods_list);
	cout<<"\n";
	}
	catch(Invalid_input)
	{
		cerr<<"\n Error: Can only advance foward\n";
	}
	catch(...)
	{
		cerr<<"Exception unknown\n";
	}
}
