#include<bits/stdc++.h>
using namespace std;
int calculate(int a,int b,char c)
{
	switch(c)
	{
		case '+' :return a+b;
		case '-' :return b-a;
		case '*' :return a*b;
		case '/' :return b/a;
		case '^' :return b^a;
	}
}
int precedence(char a)
{
	switch(a)
	{
	    case '+' :
		case '-' :return 1;
		case '*' :
		case '/' :return 2;
		case '^' :return 3;
	}
	return -1;
}
int evaluate(string s)
{
	stack<char>ops;
	stack<int>values;
	int i=0;
	for(i=0;i<s.length();i++)
	{
		if(s[i]==' ')
		continue;
		else if(s[i]=='(')
		ops.push(s[i]);
		else if(isdigit(s[i]))
		{  int val=0;
			while(i<s.length()&&isdigit(s[i]))
			{
			val=val*10+(s[i]-'0');
			i++;
		    }
		    values.push(val);
		}
		else if(s[i]==')')
		{
			while(ops.top()!='(')
			{
				int a=values.top();
				values.pop();
				int b=values.top();
				values.pop();
				char c=ops.top();
				ops.pop();
				int d=calculate(a,b,c);
				values.push(d);
			}
			ops.pop();
		}
		else
		{
			while(!ops.empty()&&precedence(ops.top())>=precedence(s[i]))
			{
				int a=values.top();
				values.pop();
				int b=values.top();
				values.pop();
				char c=ops.top();
				ops.pop();
				int d=calculate(a,b,c);
				values.push(d);
			}
			ops.push(s[i]);
		}	
	}
	while(!ops.empty())
	{	int a=values.top();
				values.pop();
				int b=values.top();
				values.pop();
				char c=ops.top();
				ops.pop();
				int d=calculate(a,b,c);
				values.push(d);
	}
	return values.top();
}
int main()
{
    cout << evaluate("10 + 2 * 6") << "\n";
    cout << evaluate("100 * 2 + 12") << "\n";
    cout << evaluate("100 * ( 2 + 12 )") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14");
    return 0;
}
