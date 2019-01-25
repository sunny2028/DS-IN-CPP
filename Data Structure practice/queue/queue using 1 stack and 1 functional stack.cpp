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
};
void push(stack **s,int x)
{
	stack *newnode=new stack;
	newnode->data=x;
	newnode->next=*s;
	*s=newnode;
}
int pop(stack **s)
{
	if(s==NULL)
	return -1 ;
	stack *t=*s;
	*s=(*s)->next;
	int d=t->data;
	delete t;
	return d;
}
void enque(queue *q,int x)
{
	push(&q->stack1,x);
}
int dequeue(queue *q)
{
	if(q->stack1==NULL)
	return -1;
	if(q->stack1->next==NULL)
	{
		return(pop(&q->stack1));
	}
	int temp=pop(&q->stack1);
	int t=dequeue(q);
	push(&q->stack1,temp);
	return t;
}
int main()
{
	queue *q=new queue;
	q->stack1=NULL;
	enque(q,1);
	enque(q,2);
	enque(q,3);
	enque(q,4);
cout<<dequeue(q);	
cout<<dequeue(q);
cout<<dequeue(q);	
cout<<dequeue(q);	
enque(q,5);
cout<<dequeue(q);
}
