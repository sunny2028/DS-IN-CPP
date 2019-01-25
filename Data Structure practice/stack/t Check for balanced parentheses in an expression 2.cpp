#include<bits/stdc++.h>
using namespace std;
bool check(char *a)
{stack<char>s;
for(int i=0;i<strlen(a);i++)
{if(a[i]=='['||a[i]=='{'||a[i]=='(')
  s.push(a[i]);
  if(a[i]==']')
{if(s.empty())
return false;
if(s.top()=='[')
s.pop();
else
return false;
}
if(a[i]=='}')
{if(s.empty())
return false;
if(s.top()=='{')
s.pop();
else
return false;
}
if(a[i]==')')
{if(s.empty())
return false;
if(s.top()=='(')
s.pop();
else
return false;
}
}
if(s.empty())
return true;
else
return false;
}
int main()
{char a[]="[(])";
bool flag=check(a);
cout<<flag;
}
