#include<iostream>
using namespace std;
struct deque
{
	int front;
	int rear;
	int capacity;
	int *arr;
};
deque *create(int x)
{deque *q=new deque;
q->front=q->rear=-1;
q->capacity=x;
q->arr=new int[q->capacity];
return q;
}
int deleteatfront(deque *q)
{ int x;
	if(q->front==-1)
	return -1;
	else if(q->front==q->rear)
	{
		 x=q->arr[q->front];
		q->front=q->rear=-1;
	}
	else
	{
		 x=q->arr[q->front];
		q->front=(q->front+1+q->capacity)%q->capacity;
	}
	return x;
}
int deleteatlast(deque *q)
{  int x;
	if(q->front==-1)
	return -1;
	else if(q->front==q->rear)
	{
		x=q->arr[q->front];
		q->front=q->rear=-1;
	}	
	else
	{
	    x=q->arr[q->rear];
		q->rear=(q->rear-1+q->capacity)%q->capacity;
	}
	return x;
}

void insertatfront(deque *q,int x)
{ 
if((q->rear+1)%q->capacity==q->front)
return;
	if(q->front==-1)
	{
		q->front=q->rear=0;
		q->arr[q->front]=x;
	}
	else
	{
	q->front=(q->front+q->capacity-1)%q->capacity;
	q->arr[q->front]=x;
	}
}
void insertatend(deque *q,int x)
{
	if((q->rear+1)%q->capacity==q->front)
      return;
      	if(q->front==-1)
	{
		q->front=q->rear=0;
		q->arr[q->front]=x;
	}
	else
	{
		q->rear=(q->rear+1)%q->capacity;
		q->arr[q->rear]=x;
	}
}
void display(deque *q)
{int k,i;
	for(i=q->front,k=0;k<(q->capacity+q->rear-q->front+1)%q->capacity;i=(i+q->capacity+1)%q->capacity,k++)
	{
		cout<<q->arr[i]<<" ";
	}
	cout<<"\n";
}
int main()
{
	deque *q=create(7);
	insertatfront(q,1);
	insertatend(q,2);
	insertatfront(q,3);
	insertatfront(q,4);
	insertatend(q,5);
	display(q);
	cout<<deleteatfront(q)<<"\n";
	cout<<deleteatlast(q)<<"\n";
	display(q);
}

