#include<bits/stdc++.h>
using namespace std;
string convert(string s)
{ 	
	stack<int>st;
	st.push(0);
	string result="";
	int i=0;
	while(i<s.length())
	{
		if(s[i]=='+'||s[i]=='-')
		{
			if(st.top()==0)
			result+=s[i];
			else
			{
				if(s[i]=='+')
				result+='-';
				else
				result+='+';
			}
		}
		else if(s[i]=='('&&i!=0)
		{char c=s[i-1];
		if(st.top())
		{
			if(c=='-')
			st.push(0);
			else
			st.push(st.top());
		}
		else
		{
			if(c=='-')
			st.push(1);
			else
			st.push(st.top());
		}
		}
		else if(s[i]==')')
		st.pop();
		else
		result+=s[i];
		i++;
	
	}
	return result;
}
int main()
{
	string s="a-(b-(c+d))";
 cout<<convert(s);
}
