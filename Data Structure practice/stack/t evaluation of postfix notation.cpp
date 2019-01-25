#include<bits/stdc++.h>
using namespace std;
bool isoperand(char a)
{if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^')
    return true;
    else
    return false;
}
int evaluate(char a,int b,int c)
{if(a=='+')
return c+b;
else if(a=='-')
return c-b;
else if(a=='*')
return c*b;
else if(a=='/')
return c/b;
else if(a=='^')
return c^b;
}
int evaluatepostfix(char a[])
{stack<int>s;
for(int i=0;i<strlen(a);i++)
{if(a[i]>='0'&&a[i]<='9')
s.push(a[i]-48);
else if(isoperand(a[i]))
{
int c=s.top();
s.pop();
int b=s.top();
s.pop();
int num=evaluate(a[i],c,b);
s.push(num);
}
}
int d=s.top();
s.pop();
return d;
}
int main()
{char a[]="231*+9-";
cout<<evaluatepostfix(a);
}
