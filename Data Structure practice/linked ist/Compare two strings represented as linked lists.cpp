#include<bits/stdc++.h>https://https://www.geeksforgeeks.org/compare-two-strings-represented-as-linked-lists/
using namespace std;//time complexity:O(n)
struct node
{char data;
node *next;
};
void push(node **head,char data)
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
int check(node *a,node *b)
{while(a&&b)
{if(a->data<b->data)
return -1;
if(a->data>b->data)
return -1;
a=a->next;
b=b->next;
}
if(a==NULL&&b==NULL)
return 0;
if(a==NULL)
return -1;
if(b==NULL)
return 1;
}
int main()
{node *head=NULL;
push(&head,'b');
push(&head,'a');
push(&head,'s');
push(&head,'k');
push(&head,'e');
push(&head,'e');
push(&head,'g');
display(head);
node *head1=NULL;

push(&head1,'s');
push(&head1,'k');
push(&head1,'e');
push(&head1,'e');
push(&head1,'g');
display(head1);
cout<<check(head,head1);
return 0;
}
