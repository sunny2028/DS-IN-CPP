#include<iostream>//https://www.geeksforgeeks.org/queue-using-stacks/
using namespace std;
struct node
{int data;
node *next;
};
struct queue
{node *stack1;
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
{if(q->stack1==NULL)
{
cout<<"stack empty";
return -1;
}
else if(q->stack1->next==NULL)
{
int x=pop(&q->stack1);
return x;
}
int x=pop(&q->stack1);
int res=dequeue(q);
push(&q->stack1,x);
return res;
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
enqueue(q,1);
enqueue(q,2);
enqueue(q,3);
cout<<dequeue(q)<<"\n";
cout<<dequeue(q)<<"\n";
}
