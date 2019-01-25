#include<bits/stdc++.h>
using namespace std;
class stack1
{
	queue<int>q1,q2;
	int currsize;
	public:  stack1()
	{
		currsize=0;
	}
	void push(int x)
	{
		q2.push(x);
		while(!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
		queue<int>q=q1;
		q1=q2;
		q2=q;
	}
	void pop()
	{
		q1.pop();
	}
	int top()
	{
		return q1.front();
	}
	int size()
	{
		return q1.size();
	}
	
};
int main()
{stack1 s;
s.push(4);
s.push(3);
s.push(2);
s.push(1);
s.pop();
cout<<s.top();
s.pop();
cout<<s.top();
s.pop();
cout<<s.top();
cout<<s.size();
	
}
