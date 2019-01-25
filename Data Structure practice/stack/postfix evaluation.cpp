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

int evaluate(string s)
{ stack<int>values;
int i;
		for(i=0;i<s.length();i++)
	{
		if(s[i]==' ')
		continue;
		else if(isdigit(s[i]))
		{  int val=0;
			while(i<s.length()&&isdigit(s[i]))
			{
			val=val*10+(s[i]-'0');
			i++;
		    }
		    values.push(val);
		}
		else
		{
				int a=values.top();
				values.pop();
				int b=values.top();
				values.pop();
				int d=calculate(a,b,s[i]);
				values.push(d);
		}
	}
		return values.top();
		
}
int main()
{
    cout << evaluate("100 200 + 2 / 5 * 7 +") << "\n";
//    cout << evaluate("100 * 2 + 12") << "\n";
//    cout << evaluate("100 * ( 2 + 12 )") << "\n";
//    cout << evaluate("100 * ( 2 + 12 ) / 14");
    return 0;
}
