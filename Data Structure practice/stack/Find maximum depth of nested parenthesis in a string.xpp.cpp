#include<bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{stack<char>st;
int maxsize=0;
for(int i=0;i<s.length();i++)
{
	if(s[i]=='(')
	st.push(i);
	else if(s[i]==')')
	{int n=st.size();  
	  maxsize=max(maxsize,n);
		if(!st.empty())
		{
			st.pop();
		}
		else
		return -1;
	}
}
if(!st.empty())
return -1;
return maxsize;
	
}
int main()
{
	string s="( ((X)) (((Y))) )";
    cout << maxDepth(s);
    return 0;
}
