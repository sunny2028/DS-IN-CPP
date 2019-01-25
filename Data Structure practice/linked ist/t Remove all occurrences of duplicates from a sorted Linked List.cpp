#include<bits/stdc++.h>//https://www.geeksforgeeks.org/remove-occurrences-duplicates-sorted-linked-list/
using namespace std;//time complexity:O(n) auxiiary space:O(1)
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
void simplify(node **head)
{node *curr=*head;
int flag;
node *prev=NULL;
while(curr)
{int key=curr->data;
flag=0;
node *temp=curr->next;
node *temp1=temp;
while(temp&&temp->data==key)
{temp=temp->next;
flag=1;
}
if(temp==temp1)
prev=curr;
if(prev==NULL&&flag==1)
{*head=temp;
}
if(prev!=NULL&&flag==1)
prev->next=temp;
curr=temp;
}
}
int main()
{node *head=NULL;
push(&head,53);
push(&head,53);
push(&head,49);
push(&head,49);
push(&head,35);
push(&head,28);
push(&head,28);
push(&head,23);
push(&head,23);
display(head);
simplify(&head);
display(head);
}
