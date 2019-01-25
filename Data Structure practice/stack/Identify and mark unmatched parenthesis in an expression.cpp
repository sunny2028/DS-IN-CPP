#include<bits/stdc++.h>
using namespace std;
void convert(string s)
{
	stack<int>st;
	int arr[s.length()];
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==')')
		{
			if(st.empty())
			{
			arr[i]=-1;	
			}
			else
			{
				while(!st.empty()&&s[st.top()]!='(')
				{
					arr[st.top()]=s[st.top()];
					st.pop();
				}
				if(st.empty())
				arr[i]=-1;
				else
				{
				arr[st.top()]=0;
				st.pop();
				arr[i]=1;
			    }
			}
		}
		else
		st.push(i);
	}

	while(!st.empty())
	{
		if(s[st.top()]>='a'&&s[st.top()]<='z')
		arr[st.top()]=s[st.top()];
		else
		arr[st.top()]=-1;
		st.pop();
	}
	for(int j=0;j<s.length();j++)
	{
		if(arr[j]!=0&&arr[j]!=-1&&arr[j]!=1)
		cout<<char(arr[j]);
		else
		cout<<arr[j];
	}
}
int main()
{
	string s="(((abc))((d)))))";
	convert(s);
}
