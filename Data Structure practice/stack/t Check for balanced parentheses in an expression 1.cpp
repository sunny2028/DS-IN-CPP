#include<iostream>
#include<cstring>
using namespace std;
struct stack
{int top;
int capacity;
int *arr;
};
stack *createstack(int a)
{stack *newnode=new stack;
newnode->capacity=a;
newnode->top=-1;
newnode->arr=new int[a];
return newnode;
}
void push(stack *s,char ch)
{s->arr[++s->top]=ch;
}
int top(stack *s)
{
return(s->arr[s->top]);
}
int pop(stack *s)
{
return (s->arr[s->top--]);
}
bool isempty(stack *s)
{

    return(s->top==-1);
}
bool check(char *a)
{//if(strlen(a)%2!=0)
//return false;
stack *s=createstack(strlen(a));
int i,k;
for(i=0;a[i];i++)
{if(a[i]=='['||a[i]=='{'||a[i]=='(')
   push(s,a[i]);
   else if(a[i]==']')
   {while(!isempty(s)&&top(s)!='[')
     pop(s);
     if(!isempty(s)&&top(s)=='[')
     pop(s);
     else if(isempty(s))
     push(s,a[i]);
   }
   else if(a[i]=='}')
   {while(!isempty(s)&&top(s)!='{')
     pop(s);
     if(!isempty(s)&&top(s)=='{')
         pop(s);
     else if(isempty(s))
     push(s,a[i]);
   }
   else if(a[i]==')')
   {while(!isempty(s)&&top(s)!='(')
     pop(s);
     if(!isempty(s)&&top(s)=='(')
     pop(s);
     else if(isempty(s))
     push(s,a[i]);
     //cout<<s->arr[s->top]<<"kjhh";
   }
}
if(isempty(s))
return true;
else
return false;
}
int main()
{char a[]="[()]{}{[()()]()}";
bool flag=check(a);
cout<<flag;



}
