#include<bits/stdc++.h>https://https://www.geeksforgeeks.org/compare-two-strings-represented-as-linked-lists/
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
void combine(node **head)
{node *temp=(*head)->next;
int k,k1;
node *q=*head;
if(((*head)->data)%2==0)
k=0;
else
k=1;
while(temp)
{if((temp->data)%2==0)
k1=0;
else
k1=1;
if(k1==k)
{q->next=temp->next;
node *t=temp->next;
temp->next=*head;
*head=temp;
temp=t;
}
else
{q=temp;
temp=temp->next;
}
}
}

int main()
{node *head=NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,6);
display(head);
combine(&head);
display(head);
}
