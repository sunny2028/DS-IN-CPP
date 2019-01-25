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
int num1;
for(int i=0;i<strlen(a);i++)
{if(a[i]>='0'&&a[i]<='9')
{   num1=0;
    while(a[i]!=' ')
{
    num1=num1*10+(a[i]-48);
    i++;
}
    s.push(num1);

}

else if(isoperand(a[i]))
{
int c=s.top();
s.pop();
int b=s.top();
s.pop();
int num=evaluate(a[i],c,b);
s.push(num);
i++;
}
}
int d=s.top();
s.pop();
return d;
}
int main()
{char a[]="23 1 7 * + 9 -";
cout<<evaluatepostfix(a);
}
