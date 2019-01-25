#include<iostream>//time complexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/delete-n-nodes-after-m-nodes-of-a-linked-list/
struct node{
int data;
node *next;
};
void push(node **head,int data)
{node *newnode=new node;
newnode->data=data;
newnode->next=*head;
*head=newnode;
}
void display(node *head)
{node *temp=head;
while(temp!=NULL)
{cout<<temp->data<<" ";
temp=temp->next;
}
cout<<"\n";
}
void del(node **head,int m,int n)
{node *temp=*head,*p,*q1;
int flag,count=0,count1=0,flag1=0;
while(temp)
{
count++;

flag=0;
if(count<=m&&flag1==0)
{p=temp;
temp=temp->next;
count1=0;
flag=1;
}
if(count1<n&&flag==0)
{p->next=temp->next;
q1=temp;
delete q1;
temp=p->next;
count=0;
flag1=1;
count1++;
}

if(count1>=n)
flag1=0;
}

}
int main()
{node *head=NULL;
    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    display(head);
    del(&head,2,3);
    display(head);

}
