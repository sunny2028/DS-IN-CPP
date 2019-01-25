#include<bits/stdc++.h>
using namespace std;
bool duplicate(string s)
{
	stack<char>st;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!=')')
		st.push(s[i]);
		else
		{  int count=0;
			while(st.top()!='(')
			{
				count++;
				st.pop();
			}
			st.pop();
			if(count<=1)
			return true;
		}
	}
	return false;
}
using namespace std;
int main()
{
 string s = "(a+(b)/c)";
	if(duplicate(s))
	cout<<"duplicate found";
	else
	cout<<"duplicate not found";
}
