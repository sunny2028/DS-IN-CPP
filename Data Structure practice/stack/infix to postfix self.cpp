#include<bits/stdc++.h>
using namespace std;
bool isoperand(char a)
{if(a>='a'&&a<='z'||a>='A'&&a<='Z')
return true;
else return false;
}
bool isoperator(char a)
{if(a=='+'||a=='-'||a=='*'||a=='^')
    return true;
    else return false;
}
int value(char a)
{switch(a)
{case '+':
case '-':return 1;
case '*':
case '/':return 2;
case '^':return 3;
default :return -1;
}
}
void infixtopostfix(char *a)
{stack<char>s;
int k=-1;
for(int i=0;a[i];i++)
{if(isoperand(a[i]))
    a[++k]=a[i];
    else if(a[i]=='(')
    s.push(a[i]);
    else if(isoperator(a[i]))
    {while(!s.empty()&&value(s.top())>=value(a[i]))
         {
         a[++k]=s.top();
         s.pop();
         }
         s.push(a[i]);
    }
    else if(a[i]==')')
    {while(!s.empty()&&s.top()!='(')
         {a[++k]=s.top();
         s.pop();
         }
         if(!s.empty()&&s.top()!='(')
               return ;
               s.pop();
    }
}
while(!s.empty())
{a[++k]=s.top();
s.pop();
}
a[++k]='\0';
cout<<a;
}
int main()
{char a[]="a+b*(c^d-e)^(f+g*h)-i";
infixtopostfix(a);
return 0;
}
