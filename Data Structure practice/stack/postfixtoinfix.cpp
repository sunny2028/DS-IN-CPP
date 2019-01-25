#include<bits/stdc++.h>
using namespace std;
bool isoperand(char a)
{
	return (a>='a'&&a<='z')||(a>='A'&&a<='Z');
}
void postfixtoinfix(string a)
{
	stack<string>s;
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if(isoperand(a[i]))
	{
		string op(1,a[i]);
		s.push(op);
		
	}
		else
		{
			string op1=s.top();
			s.pop();
			string op2=s.top();
			s.pop();
			s.push("("+op2+a[i]+op1+")");
		}
	}
	cout<<s.top();
}
int main()
{ string exp="ab*c+";
postfixtoinfix(exp);
return 0;
}
