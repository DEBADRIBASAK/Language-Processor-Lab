#include <bits/stdc++.h>

using namespace std;


class dict
{
private:
	map<int,int> m;
public:
	int& operator [](int k)
	{
		return m[k];
	}

};

int main(int argc, char const *argv[])
{
	dict d;
	d[1] = 2;
	cout<<d[1]<<endl;
	d[1] = 3;
	cout<<d[1]<<endl;
	//cout<<d.to_string()<<endl;
	return 0;
}