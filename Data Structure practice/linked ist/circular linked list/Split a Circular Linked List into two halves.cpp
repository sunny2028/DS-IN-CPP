#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
void push(node **head,int data)
{
	node *temp=*head;
	node *newnode=new node;
	newnode->data=data;
	newnode->next=*head;
	if(*head==NULL)
	newnode->next= newnode;
	else
	{
		while(temp->next!=(*head))
		temp=temp->next;
		temp->next=newnode;
	}
	*head=newnode;
}
void printlist(node *head)
{
	node *temp=head;
	do
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=head);
	cout<<"\n";
}
void split(node *head)
{
	node *head1=head;
	node *head2=NULL;
	node *prev;
	node *slow=head;
	node *fast=slow->next;
	while(fast!=head&&fast->next!=head)
	{prev=fast;
		fast=fast->next->next;
		slow=slow->next;
	}
	node *next=slow->next;
	if(fast==head)
	prev->next->next=next;
	else
	fast->next=next;
	head2=next;
	slow->next=head1;
	printlist(head1);
	printlist(head2);
	
}
int main()
{node *head=NULL;
//push(&head,1);
//push(&head,2);
//push(&head,3);
//push(&head,4);
push(&head,5);
printlist(head);
split(head);
}
