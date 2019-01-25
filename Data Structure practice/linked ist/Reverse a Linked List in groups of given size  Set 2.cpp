#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
void push(node **head,int data)
{
	node *newnode=new node;
	newnode->data=data;
	newnode->next=*head;
	*head=newnode;
}
void display(node *head)
{
	
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
node * reverse(node **head,int k)
{
	
	
	stack<node*>s;
	node *curr=*head;
	node *prev=NULL;

	while(curr!=NULL)
	{	int count=0; 
	while(curr!=NULL&&count<k)
	{
		s.push(curr);
		curr=curr->next;
		count++;
	}
	while(s.size()>0)
	{if(prev==NULL)
	{
		prev=s.top();
		*head=prev;
		s.pop();
	}
	else
	{ 
		prev->next=s.top();
		prev=prev->next;
		s.pop();
	}
	}	
	}
	prev->next=NULL;
	return *head;
}
int main()
{
	node *head=NULL;
	push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 head=reverse(&head,3);
 display(head);
	}
