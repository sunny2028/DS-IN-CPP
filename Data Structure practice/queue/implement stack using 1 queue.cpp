#include<bits/stdc++.h>
using namespace std;
class Stack
{
	queue<int>q;
	public: void push(int x)
	{  int j=q.size();
		q.push(x);
		for(int i=0;i<j;i++)
		{
			q.push(q.front());
			q.pop();
	    }
	}
	void pop()
	{
		if(!q.empty())
		q.pop();
	}
	int top()
	{
		return q.front();
	}
};
int main()
{
	 Stack s;
    s.push(10);
    s.push(20);
    cout << s.top() << endl;
    s.pop();
    s.push(30);
    s.pop();
    cout << s.top() << endl;
    return 0;
}
