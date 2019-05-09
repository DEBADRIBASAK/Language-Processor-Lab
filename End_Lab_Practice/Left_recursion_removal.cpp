#include <bits/stdc++.h>

using namespace std;

typedef pair<string,vector<string> > Rule;

int main(int argc, char const *argv[])
{
	int n;
	cout<<"How many non-terminals?"<<endl;
	cin>>n;
	vector<Rule> a(n);
	string s="";
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the non-terminal"<<endl;
		cin>>a[i].first;
		cout<<"Enter all the derivations"<<endl;
		while(1)
		{
			cin>>s;
			if(s=="-1")
				break;
			a[i].second.push_back(s);
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i].first<<" :: ";
		for(int j=0;j<a[i].second.size();j++)
		{
			cout<<a[i].second[j]<<"|";
		}
		cout<<endl;
	}

	cout<<endl<<"Left recursion removed"<<endl;
	int i1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			i1 = 0;
			for(int k=0;k<a[i].second.size();k++)
			{
				if(a[i].second[k][0]==a[j].first[0])
				{
					for(int l=0;l<a[j].second.size();l++)
					{
						a[i].second.push_back(a[j].second[l]+a[i].second[k].substr(1,a[i].second[k].size()-1));
					}
					swap(a[i].second[i1],a[i].second[k]);i1++;
				}
			}
			while(i1--)
			{
				a[i].second.erase(a[i].second.begin());
			}
		}
		vector<string> v,v1;
		for(int j=0;j<a[i].second.size();j++)
		{
			if(a[i].first[0]==a[i].second[j][0]) //left recursion
			{
				v.push_back(a[i].second[j].substr(1,a[i].second[j].size()-1));
			}
			else
				v1.push_back(a[i].second[j]);
		}
		if(v.size()!=0)
			{
				s = "";
				s+=a[i].first[0];s+="'";
				for(int k=0;k<v1.size();k++)
				{
					if(v1[k]!="@")
					v1[k]+=s;
					else
					v1[k] = s;
				}
				for(int k=0;k<v.size();k++)
				{
					v[k]+=s;
				}
				v.push_back("@");
				a[i].second = v1;
				a.push_back(make_pair(s,v));
			}
	}
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i].first<<" :: ";
		for(int j=0;j<a[i].second.size();j++)
		{
			cout<<a[i].second[j]<<"|";
		}
		cout<<endl;
	}
	return 0;
}

/*
1
E
E+E
E*E
(E)
i
-1


3
E
E+T
T
-1
T
T*F
F
-1
F
(E)
i
-1

*/