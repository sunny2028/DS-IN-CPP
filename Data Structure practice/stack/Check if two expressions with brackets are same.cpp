#include<bits/stdc++.h>
using namespace std;
bool getsign(string s,int i)
{
	if(i==0)
	return true;
	else if(s[i-1]=='-')
	return false;
	return true;
}
void eval(string s,vector<int> &v,bool flag)
{
	int i=0;
	stack<bool>st;
	st.push(true);
	while(s[i])
	{
		if(s[i]=='+'||s[i]=='-')
		{
			i++;
			continue;
		}
		else if(s[i]=='(')
		{
			if(getsign(s,i))
			st.push(true);
			else
			st.push(false);
		}
		else if(s[i]==')')
		st.pop();
		else
		{ if(st.top())
			v[s[i]-'a']+=getsign(s,i)?flag?1:-1
			                         :flag?-1:1;
           else
           v[s[i]-'a']+=getsign(s,i)?flag?-1:1
                                    :flag?1:-1;
		}
		i++;
	}
}
bool check(string s,string s1)
{
	vector<int>v(26,0);
	
	eval(s,v,true);
	eval(s1,v,false);
	for(int i=0;i<v.size();i++)
	{
		if(v[i]!=0)
		return false;
	}
	return true;
}
int main()
{
	string s="-(a+b+c)";
	string s1="-a-b-c";
	cout<<check(s,s1);
}
