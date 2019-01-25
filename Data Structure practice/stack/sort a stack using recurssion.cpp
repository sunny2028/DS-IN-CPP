#include<bits/stdc++.h>
using namespace std;
void insertinsortedorder(stack<int>&s,int k)
{
	if(s.empty()||k<s.top())
	{
		s.push(k);
		return;
	}
	int t=s.top();
	s.pop();
	insertinsortedorder(s,k);
	s.push(t);
}
void sort(stack<int> &s)
{
	if(s.empty())
	return;
	int a=s.top();
	s.pop();
	sort(s);
	insertinsortedorder(s,a);
}
int main()
{
	stack<int> s;
	s.push(1);
		s.push(5);
			s.push(3);
			sort(s);
cout<<s.top();
s.pop();
cout<<s.top();
s.pop();
cout<<s.top();
s.pop();			
	
}
