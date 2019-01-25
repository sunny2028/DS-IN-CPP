#include<bits/stdc++.h>
using namespace std;
int check(queue<int>q)
{
	stack<int>s;
	int k=1;
	while(!q.empty())
	{if(q.front()==k)
		{
				k++;
		}
		else
		s.push(q.front());
		q.pop();
	}
	int j=k;
	while(!s.empty())
	{
		if(s.top()==j)
		{
			s.pop();
			j++;
		}
		else
		return 0;
	}
	return 1;
	
	
}
int main()
{
	queue<int>q;
	  q.push(6);
    q.push(1);
    q.push(2);
      q.push(5);
    q.push(3);
    q.push(4);
    cout<<check(q);
    cout<<q.front();
    
}
