#include<iostream>https://https://www.geeksforgeeks.org/reverse-a-linked-list/
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
void rev(node **head)
{node *prev=NULL,*curr=*head,*next=NULL;
while(curr)
{next=curr->next;
curr->next=prev;
prev=curr;
curr=next;
}
*head=prev;
}

int main()
{node *head=NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);
display(head);
rev(&head);
display(head);
}
