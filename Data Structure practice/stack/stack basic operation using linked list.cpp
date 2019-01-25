#include<iostream>
using namespace std;
struct stack
{int data;
stack *next;
};
void push(stack **top,int data)
{stack *newnode=new stack;
newnode->data=data;
newnode->next=*top;
*top=newnode;
}
int pop(stack **top)
{if(*top==NULL)
{cout<<"stack underflow";
return -1;
}
stack *temp=*top;
*top=(*top)->next;
int data=temp->data;
delete temp;
return data;
}
void show(stack *top)
{stack *temp=top;
while(temp)
{cout<<temp->data<<" ";
temp=temp->next;
}
cout<<"\n";
}
int gettop(stack *top)
{if(top)
return top->data;
else
return INT_MIN;
}
void deletestack(stack **top)
{if(*top==NULL)
return ;
else
{while(*top)
{stack *temp=*top;
*top=(*top)->next;
delete temp;
}
cout<<"NULL";
}
}
int main()
{stack *top=NULL;
push(&top,8);
push(&top,7);
push(&top,6);
push(&top,5);
push(&top,4);
push(&top,3);
push(&top,2);
push(&top,1);
cout<<pop(&top)<<"\n";
show(top);
cout<<gettop(top)<<"\n";
deletestack(&top);
}
