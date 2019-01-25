#include<bits/stdc++.h>
using namespace std;
void reverse1(stack<int>&s,int k)
{
	if(s.empty())
	{
		s.push(k);
		return;
	}
	int t=s.top();
	s.pop();
	reverse1(s,k);
	s.push(t);
}
void reverse(stack<int> &s)
{
	if(s.empty())
	return;
	int a=s.top();
	s.pop();
	reverse(s);
	reverse1(s,a);
}
int main()
{
	stack<int> s;
	s.push(1);
		s.push(2);
			s.push(3);
			reverse(s);
cout<<s.top();
s.pop();
cout<<s.top();
s.pop();
cout<<s.top();
s.pop();			
	
}
