#include<bits/stdc++.h>
using namespace std;
class stack1
{queue<int>q1,q2;
public:void push(int x)
        {
        	q1.push(x);
		}
		void pop()
		{
			if(q1.size()==0)
			return;
			while(q1.size()>1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
			queue<int>q=q1;
			q1=q2;
			q2=q;
		}
		int top()
		{
			return q1.rear();
		}
		int size()
		{
			return q1.size();
		}
	
}
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
