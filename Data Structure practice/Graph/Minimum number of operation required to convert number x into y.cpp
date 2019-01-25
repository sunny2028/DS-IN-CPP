#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	int level;
};
int minOperations(int x,int y)
{   set<int>s;
	queue<node>q;
	node n={x,0};
	q.push(n);
	while(q.size()>0)
	{
		node t=q.front();
		q.pop();
		if(t.val==y)
		{
		return t.level;
		}
		if(t.val*2==y||t.val-1==y)
		return t.level+1;
		s.insert(t.val);
		if(s.find(t.val*2)==s.end())
		{
		    n.val=t.val*2;
		    n.level=t.level+1;
		    q.push(n);
		}
		if(s.find(t.val-1)==s.end()&&t.val-1>0)
		{
			 n.val=t.val-1;
		    n.level=t.level+1;
		    q.push(n);
		}
	}
}
int main() 
{ 
    int x = 4, y = 7; 
    cout << minOperations(x, y); 
    return 0; 
} 
