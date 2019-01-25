#include<bits/stdc++.h>
using namespace std;
struct node
{
	int top;
	int capacity;
	char *arr;
};
node *createstack(int len)
{
	node *s=new node;
	s->top=-1;
	s->capacity=len;
	s->arr=new char[len];
	return s;
}
void push(node *s,char a)
{
	s->arr[++s->top]=a;
}
bool isoperand(char a)
{
	return(a>='a'&&a<='z')||(a>='A'&&a<='Z');
}
bool isempty(node *s)
{
	return(s->top==-1);
}
void pop(node *s)
{
   	s->top--;
}
char top(node *s)
{
	return s->arr[s->top];
}
int prec(char a)
{
	switch(a)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '^':return 3;
	}
	return -1;
}
void infixtopostfix(char *a)
{
	node *s=createstack(strlen(a));
	int k=-1;
	for(int i=0;a[i];i++)
	{
		if(isoperand(a[i]))
		{k++;
		a[k]=a[i];
	//	cout<<a<<'\n';
	}
		else if(a[i]=='(')
		push(s,a[i]);
		else if(a[i]==')')
		{
			while(!isempty(s)&&top(s)!='(')
			{k++;
			a[k]=top(s);
			pop(s);
		    }
			pop(s);	
		}
		else
	{
			while(!isempty(s)&&prec(a[i])<=prec(top(s)))
                 {k++;
                 	a[k]=top(s);
                 	pop(s);
				 }
				 push(s,a[i]);
        
	}

	}
	//	cout<<a<<'\n';
	while(!isempty(s))
	{k++;
	  a[k]=top(s);
	  pop(s);
    }
    a[++k]='\0';
    cout<<a;
}
int main()
{
	
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixtopostfix(exp);
    return 0;
}
