#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
Node* XOR(Node *a,Node *b)
{
	return (Node*)((uintptr_t)(a)^(uintptr_t)(b));
}
void insert(Node **head,int data)
{
	Node *newnode=new Node;
	newnode->data=data;
	newnode->next=*head;
	*head=newnode;
}
void convert(Node *head)
{
	Node *prev=NULL,*next=NULL;
	Node *curr=head;
	while(curr)
	{next=curr->next;
	curr->next=XOR(prev,next);
	prev=curr;
	curr=next;
	}	
}
void pairsum(Node *head,int d)
{Node *temp=head;
Node *prev=NULL;
while(temp->next!=prev)
{  Node *temp1=temp;
	temp=XOR(temp->next,prev);
	prev=temp1;
}
prev=NULL;
Node *succ=NULL;
while(head!=NULL&&temp!=NULL&&head!=temp&&head!=succ)
{
	
	if(head->data+temp->data==d)
	{
		cout<<"[ "<<head->data<<","<<temp->data<<" ]"<<"\n";
		Node *a=head;
		head=XOR(head->next,prev);
		prev=a;
		Node *b=temp;
		temp=XOR(temp->next,succ);
		succ=b;
	}
	else if(head->data+temp->data < d)
	{
			Node *a=head;
		head=XOR(head->next,prev);
		prev=a;
	}
	else
	{
		Node *b=temp;
		temp=XOR(temp->next,succ);
		succ=b;
	}
}
	
	
}
int main()
{
	Node *head=NULL;
/*	insert(&head,7);
	insert(&head,6);*/
	insert(&head,5);
	insert(&head,4);
	insert(&head,3);
	insert(&head,2);
	insert(&head,1);
	
	convert(head);
	pairsum(head,7);
}
