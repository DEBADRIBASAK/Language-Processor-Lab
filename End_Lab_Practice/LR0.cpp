#include <bits/stdc++.h>

struct Rules
{
	char var;
	string der;
	Rules(char c,string s)
	{
		var = c;der = s;
	}
	void print()
	{
		cout<<var<<" :: "<<der<<endl;
	}

};

struct Item
{
	int dotposition;
	Rules r;
	Item(int i,Rules r1)
	{
		dotposition = i;
		r = r1;
	}
	void print()
	{
		cout<<r.var<<" :: "<<r.der.substr(0,dotposition)<<"."<<r.der.substr(dotposition,r.der.length()-dotposition)<<endl;
	}
};

struct State
{
	vector<Item> itm;
	vector<int> transition(255,-1);
	void print()
	{
		for(int i=0;i<itm.size();i++)
		{
			itm[i].print();
		}
	}
	void insert(Item i)
	{
		itm.push_back(i);
	}
};





class LR0
{
public:
	int n;
	vector<Rules> a;
	vector<bool> variable(26,false),terminal(255,false),nullable(26,false);
	vector<vector<bool> > first(26,vector<bool>(255,false)),follow(26,vector<bool>(255,false));

	LR0()
	{
		cout<<"How many rules?\n";
		cin>>n;
		char c,string s = "";
		for(int i=0;i<n;i++)
		{
			cout<<"Enter the variable"<<endl;
			cin>>c;
			variable[c-'A'] = true;
			cout<<"Enter the derived string"<<endl;
			cin>>s;
			for(int j=0;j<s.length();j++)
			a.push_back(Rules(c,s));
		}
	}
	bool isNullable(string s)
	{
		for(int i=0;i<s.length();i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
			{
				if(!nullable[s[i]-'A'])
					return false;
			}
			else
				return false;
		}
		return true;
	}
	void findNulls()
	{
		bool noChange;
		do
		{
			noChange = false;
			for(i=0;i<n;i++)
			{
				if(a[i].der=="@"||(a[i].der!="@"&&isNullable(a[i].der)))
				{
					if(!nullable[a[i]-'A'])
					{
						noChange = true;
						nullable[a[i]-'A'] = true;
					}
				}
			}
		}while(noChange);
	}

	void findFirst()
	{
		bool noChange;
		do
		{
			noChange = false;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<a[i].length();j++)
				{
					if(a[i].der[j]<'A'||a[i].der[j]>'Z')
						break;
					else if(isNullable(a[i].der.substr(0,j)))
					{
						for(int k=0;k<255;k++)
						{
							if(first[a[i].der[j]-'A'][k]&&!first[a[i].var-'A'][k])
							{
								noChange = true;
								first[a[i].var-'A'][k] = true;
							}
						}
					}
					else
						break;
				}
			}
		}while(noChange);
	}

	void parse()
	{

	}
};