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
}
void alive(node *head,int n)
{node *temp=head;
	while(n>1)
	{node *t=temp->next;
	temp->next=t->next;
	temp=temp->next;
	delete t;
	n--;
	}
	cout<<temp->data;
}
int main()
{node *head=NULL;
push(&head,5);
push(&head,4);
push(&head,3);
push(&head,2);
push(&head,1);
printlist(head);
alive(head,5);
}
