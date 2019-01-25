#include<iostream>//https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
#include<cstring>//tie complexity:O(n) space complexity:O(1)
using namespace std;
struct mystack
{int capacity;
int top;
int *arr;
};
mystack *createstack(int x)
{mystack *newnode=new mystack;
newnode->top=-1;
newnode->capacity=x;
newnode->arr=new int[x];
return newnode;
}
bool isempty(mystack *s)
{
return (s->top==-1);
}
bool isoperand(char a)
{return (a>='a'&&a<='z')||(a>='A'&&a<='Z');
}
void push(mystack *s,char a)
{s->arr[++s->top]=a;
}
int pop(mystack *s)
{
return(s->arr[s->top--]);

}
int peek(mystack *s)
{
return(s->arr[s->top]);
}
int value(char ch)
{switch(ch)
{case '+':
case '-':return 1;
case '/':
case '*':return 2;
case '^':return 3;
}
return -1;
}
int infixtopostfix(char *a)
{mystack *s=createstack(strlen(a));
if(!s)
return -1;
int i,k;
for(i=0,k=-1;a[i];i++)
{if(isoperand(a[i]))
a[++k]=a[i];
else if(a[i]=='(')
push(s,a[i]);
else if(a[i]==')')
{while(!isempty(s)&&peek(s)!='(')
  a[++k]=pop(s);
  if(!isempty(s)&&peek(s)!='(')
  return -1;
  pop(s);
}
else
{while(!isempty(s)&&value(a[i])<=value(peek(s)))
a[++k]=pop(s);
push(s,a[i]);
}
}
while(!isempty(s))
a[++k]=pop(s);
a[++k]='\0';
cout<<a;
}

int main()
{char a[]="a+b*(c^d-e)^(f+g*h)-i";
infixtopostfix(a);
return 0;
}
