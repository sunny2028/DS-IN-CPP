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
	cout<<'\n';

}
void swap(node **head)
{
	
	node *temp=*head;
	if(temp->next->next==*head)
	{
	*head=(*head)->next;
	return;
	}
	while(temp->next->next!=*head)
	{
		temp=temp->next;
	}
	temp->next->next=(*head)->next;
	(*head)->next=temp->next;
	temp->next=*head;
	*head=(*head)->next;
}
int main()
{node *head=NULL;

push(&head,5);
printlist(head);
swap(&head);
printlist(head);
}
