#include <bits/stdc++.h>
#include <set>
#include <vector>
#include <iostream>


using namespace std;

class Rules
{
public:
	char var;
	string der;
	Rules(char var,string der)
	{
		this->var = var;
		this->der = der;
	}
	
	void print()
	{
		cout<<var<<" :: "<<der<<endl;
	}
};


bool operator >(const Rules& r1,const Rules& r)
	{
		return (r1.var>r.var)||((r1.var==r.var)&&(r1.der>r.der));
	}
	bool operator <(const Rules& r1,const Rules& r)
	{
		return (r1.var<r.var)||((r1.var==r.var)&&(r1.der<r.der));
	}
	bool operator ==(const Rules& r1,const Rules& r)
	{
		return (r1.var==r.var)&&(r1.der==r.der);
	}
	bool operator !=(const Rules& r1,const Rules& r)
	{
		return (r1.var!=r.var)||(r1.der!=r.der);
	}

set<Rules> s;
vector<Rules> v;

int main(int argc, char const *argv[])
{
	s.insert(Rules('E',"E+E"));
	s.insert(Rules('E',"E*E"));
	s.insert(Rules('E',"E+E"));
	s.insert(Rules('E',"(E)"));
	s.insert(Rules('E',"i"));

	v.push_back(Rules('E',"E+E"));
	v.push_back(Rules('E',"E*E"));
	v.push_back(Rules('E',"E+E"));
	v.push_back(Rules('E',"(E)"));
	v.push_back(Rules('E',"i"));

	vector<Rules>::iterator itr = v.begin();

	// while(itr!=v.end())
	// {
	// 	(*itr).print();itr++;
	// }

	set<Rules>::iterator itr1 = s.begin();

	while(itr1!=s.end())
	{
		cout<<itr1->var<<" :: "<<itr1->der<<endl;itr1++;
	}


	return 0;
}