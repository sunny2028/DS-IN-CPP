#include<iostream>//https://www.geeksforgeeks.org/queue-using-stacks/
using namespace std;
struct node
{int data;
node *next;
};
struct queue
{node *stack1;
node *stack2;
};
void push(node **,int);
int pop(node **);
void enqueue(queue *q,int x)
{
push(&q->stack1,x);
}
void push(node **topref,int data)
{node *newnode=new node;
newnode->data=data;
newnode->next=*topref;
*topref=newnode;
}
int dequeue(queue *q)
{if(q->stack1==NULL&&q->stack2==NULL)
{
cout<<"stack empty";
return -1;
}
if(q->stack2==NULL)
{
while(q->stack1)
{int x=pop(&q->stack1);
push(&q->stack2,x);
}
}
return pop(&q->stack2);
}
int pop(node **topref)
{node *temp=*topref;
int data=(*topref)->data;
*topref=(*topref)->next;
delete temp;
return data;
}

int main()
{
queue *q=new queue;
q->stack1=NULL;
q->stack2=NULL;
enqueue(q,1);
enqueue(q,2);
enqueue(q,3);
cout<<dequeue(q)<<"\n";
cout<<dequeue(q)<<"\n";
}
