#include<bits/stdc++.h>
using namespace std;
int calculatelength(string s)
{
	stack<char>st;
	int maximum=0;
	int count=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(')
		st.push(s[i]);
		else if(s[i]==')')
		{
			if(!st.empty())
			{
			   st.pop();
				count=count+2;
				maximum=max(maximum,count);
			  
			}
			  else
			    count=0;
		}
	}
return maximum;
}
int main()
{
	string s="(())(()";
	cout<<calculatelength(s);
}
