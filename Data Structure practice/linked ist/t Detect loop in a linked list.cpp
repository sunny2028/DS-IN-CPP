#include<iostream>https://https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
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
int check(node **head)
{node *a=*head,*b=*head;
while(b&&b->next)
{a=a->next;
b=b->next->next;
if(!b)
    break;
if(a==b)
    return 1;
}
return 0;
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
head->next->next->next->next->next->next=head;

cout<<check(&head);
}
