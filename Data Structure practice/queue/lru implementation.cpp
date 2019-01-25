#include<bits/stdc++.h>
using namespace std;
class lru
{
	list<int>s;
	//unordered_map<int,list<int>::iterator>ma;
	map<int, list<int>::iterator> ma;
	int csize;
	int count=0,hit=0;
	public:lru(int h)
	{csize=h;
	}
	void push(int x)
	{ count++;
		if(ma.find(x)==ma.end())
		{
			if(s.size()==csize)
			{
				int last=s.back();
				s.pop_back();
				ma.erase(last);
			}
		}
		else
	{
	s.erase(ma[x]);
	hit++;
    }
		
		s.push_front(x);
		ma[x]=s.begin();
	}
	void display()
	{list<int>::iterator it;
			for (it = s.begin(); it != s.end();
										it++)
		cout << (*it) << " ";

	cout << endl;
	cout<<hit<<"\n";
	cout<<count-hit<<"\n";
	}
};

int main()
{
	lru s(3);
	s.push(1);
		s.push(2);
			s.push(3);
				s.push(2);
					s.push(5);
						s.push(2);
						s.display();
}
