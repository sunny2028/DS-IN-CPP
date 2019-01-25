#include<bits/stdc++.h>
using namespace std;
bool ismatching(stack<char>st,char s)
{
	return(s==')'&&st.top()=='('||s==']'&&st.top()=='['||s=='}'&&st.top()=='{'||st.top()=='X');
	
}
int check(string s,stack<char> &st,int index)
{
	if(s[index]=='\0')
	return st.empty();
	else if(s[index]=='('||s[index]=='{'||s[index]=='[')
	{
	st.push(s[index]);
	return check(s,st,index+1);
    }
	else if(s[index]==')'||s[index]=='}'||s[index]==']')
	{
		if(ismatching(st,s[index]))
		{st.pop();
		   return check(s,st,index+1);
	    }
		   return 0;
	}
	else
	{
		stack<char>temp=st;
		temp.push(s[index]);
		int res=check(s,temp,index+1);
		if(res==1)
		return check(s,st,index+1);
		if(st.empty())
		return 0;
		st.pop();
	    return check(s,st,index+1);	
	}
}
int main()
{
	
    string s = "{(X}[]";
    stack<char>st;
    cout<<check(s,st,0);
}
