#include<bits/stdc++.h>
using namespace std;
int maximum(string s)
{    int result=0;
	stack<int>st;
	st.push(-1);
	for(int i=0;s[i];i++)
	{
		if(s[i]=='(')
		st.push(i);
		else
		{
			st.pop();
			if(!st.empty())
			   result=max(result,i-st.top());
			   else
			   st.push(i);
		}
	}
	return result;
}
int main()
{
	string s="()()";
	cout<<maximum(s);
}
