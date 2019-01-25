#include<iostream>
using namespace std;
struct node
{int data;
node *next;
};
struct queue
{node *front;
node *rear;
};
queue *createqueue()
{queue *newqueue=new queue;
node *newnode=new node;
newqueue->front=newqueue->rear=NULL;
return newqueue;
}
bool isempty(queue *ptr)
{
return ptr->front==NULL;
}
void enqueue(queue *ptr,int data)
{
node *newnode=new node;
newnode->data=data;
newnode->next=NULL;
if(ptr->rear)
ptr->rear->next=newnode;
ptr->rear=newnode;
if(!ptr->front)
ptr->front=ptr->rear;
}
int dequeue(queue *ptr)
{int data;
    if(!isempty(ptr))
{node *abc=ptr->front;;
 data=ptr->front->data;
if(ptr->front==ptr->rear)
ptr->rear=NULL;
ptr->front=ptr->front->next;
delete abc;
}
return data;
}
void deletequeue(queue *ptr)
{node *temp;
while(ptr->front)
{temp=ptr->front;
ptr->front=ptr->front->next;
delete temp;
}
delete ptr;
}
int main()
{
queue *newnode=createqueue();
enqueue(newnode,1);
enqueue(newnode,2);
enqueue(newnode,3);
cout<<dequeue(newnode)<<"\n";
cout<<dequeue(newnode)<<"\n";
cout<<isempty(newnode)<<"\n";
deletequeue(newnode);
}
