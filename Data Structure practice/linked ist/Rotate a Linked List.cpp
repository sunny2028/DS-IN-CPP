#include<iostream>https://https://www.geeksforgeeks.org/rotate-a-linked-list/
using namespace std;//time complexity:O(n)
struct node
{int data;
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
void rotate(node **head,int k)
{int count=0;
node *temp=*head;
while(count<k-1)
{count++;
temp=temp->next;
}
node *q=temp->next;
temp->next=NULL;
node *t=q;
while(t->next)
{t=t->next;
}
t->next=*head;
*head=q;
}
int main()
{node *head=NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);
push(&head,6);
display(head);
rotate(&head,5);
display(head);
}
