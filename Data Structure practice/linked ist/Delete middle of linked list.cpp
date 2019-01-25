#include<iostream>//https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/
using namespace std;//Time complexity:O(n)
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
void delmid(node *head)
{node *fast=head;
node *slow=head;
node *temp;
while(1)
{fast=fast->next->next;
temp=slow;
slow=slow->next;
if(fast==NULL)
break;
if(fast->next==NULL)
break;
}
temp->next=slow->next;
delete slow;
}
int main()
{node *head=NULL;
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);
push(&head,6);
display(head);
delmid(head);
display(head);
}
