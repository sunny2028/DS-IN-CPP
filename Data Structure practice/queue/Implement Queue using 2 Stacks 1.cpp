#include<iostream>
using namespace std;
struct stack
{
	int data;
	stack *next;
};
struct queue
{
	stack *stack1;
	stack *stack2;
};
void push(stack **q,int x)
{
	stack *newnode=new stack;
	newnode->data=x;
	newnode->next=*q;
	*q=newnode;
}
void enque(queue **q,int x)
{
	push(&(*q)->stack1,x);
}
int pop(stack **s)
{
	if(*s==NULL)
	return -1;
	stack *t=*s;
	*s=(*s)->next;
	int x=t->data;
	delete t;
	return x;
	
}
int dequeue(queue **q)
{ 
	if((*q)->stack1==NULL&&(*q)->stack2==NULL)
	    return -1;
	    if((*q)->stack2==NULL)
	     {
	     	while((*q)->stack1)
	     	{int x=pop(&(*q)->stack1);
	     	push(&(*q)->stack2,x);
			}
		 }
		 int r=pop(&(*q)->stack2);
		 return r;
}
int main()
{
	queue *q=new queue;
	q->stack1=NULL;
	q->stack2=NULL;
	enque(&q,1);
	enque(&q,2);
	enque(&q,3);
	enque(&q,4);
	 cout<<"dvxv	";
cout<<dequeue(&q);	
cout<<dequeue(&q);
cout<<dequeue(&q);	
}
