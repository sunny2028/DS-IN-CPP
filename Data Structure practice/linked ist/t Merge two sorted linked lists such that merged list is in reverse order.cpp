#include<bits/stdc++.h>https://https://www.geeksforgeeks.org/merge-two-sorted-linked-lists-such-that-merged-list-is-in-reverse-order/
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
node* mergge(node* head,node* head1)
{node *res=NULL;
while(head!=NULL&&head1!=NULL)
{if(head->data<=head1->data)
{node *temp=head->next;
head->next=res;
res=head;
head=temp;
}
else
{node *temp=head1->next;
head1->next=res;
res=head1;
head1=temp;
}
}
while(head!=NULL)
{node *temp=head->next;
head->next=res;
res=head;
head=temp;

}

while(head1!=NULL)
{node *temp=head1->next;
head1->next=res;
res=head1;
head1=temp;
}
return res;
}

int main()
{node *head=NULL;
push(&head,11);
push(&head,8);
push(&head,7);
push(&head,3);
push(&head,1);
display(head);
node *head1=NULL;
push(&head1,19);
push(&head1,14);
push(&head1,13);
push(&head1,6);
push(&head1,5);
push(&head1,4);
push(&head1,2);
display(head1);
node *temp=mergge(head,head1);
display(temp);
}
