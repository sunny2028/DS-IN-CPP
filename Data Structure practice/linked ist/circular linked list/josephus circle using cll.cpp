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
void josephuscircle(node *head,int n,int k)
{
	node *temp=head;
	while(n>1)
	{
	int count=1;
	while(count<k-1)
	temp=temp->next;
	node *t=temp->next;
	temp->next=t->next;
	delete t;
	n--;
	temp=temp->next;
	}
	cout<<'\n'<<temp->data;
}
int main()
{node *head=NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);
printlist(head);
josephuscircle(head,5,2);
}
