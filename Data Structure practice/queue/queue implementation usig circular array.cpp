#include<iostream>
using namespace std;
struct queue
{
int front;
int rear;
int capacity;
int *arr;
};
queue *createqueue(int size)
{ queue *newnode= new queue;
newnode->capacity=size;
newnode->front=newnode->rear=-1;
newnode->arr=new int[newnode->capacity];
return newnode;
}
bool isempty(queue *ptr)
{
return(ptr->front==-1);
}
bool isfull(queue *ptr)
{
return ((ptr->rear+1)%ptr->capacity==ptr->front);
}
int queuesize(queue *ptr)
{return (ptr->capacity-ptr->front+ptr->rear+1)%ptr->capacity;
}
void enqueue(queue *ptr ,int data)
{
ptr->rear=(ptr->rear+1)%ptr->capacity;
ptr->arr[ptr->rear]=data;
if(ptr->front==-1)
ptr->front=ptr->rear;
}
int dequeue(queue *ptr)
{int data=ptr->arr[ptr->front];
if(ptr->front==ptr->rear)
{
ptr->front=ptr->rear=-1;
}
else
{
ptr->front=(ptr->front+1)%ptr->capacity;
}
return data;
}
int deletequeue(queue *ptr)
{
if(ptr)
{if(ptr->arr)
 delete ptr->arr;
 delete ptr;
}
}
int main()
{
queue *newnode=createqueue(10);
enqueue(newnode,1);
enqueue(newnode,2);
enqueue(newnode,3);
cout<<queuesize(newnode)<<"\n";
cout<<dequeue(newnode)<<"\n";
cout<<queuesize(newnode)<<"\n";
cout<<dequeue(newnode)<<"\n";
cout<<isempty(newnode)<<"\n";
deletequeue(newnode);
}
