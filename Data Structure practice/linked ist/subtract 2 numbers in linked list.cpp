#include<iostream>
#include<math.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
void push(Node **head,int data)
{
	Node *newnode=new Node;
	newnode->data=data;
	newnode->next=*head;
	*head=newnode;
}
void printlist(Node* head)
	{
		while(head)
		{
			cout<<head->data<<" ";
			head=head->next;
		}
		cout<<'\n';
	}
	int calclength(Node *head)
	{int count=0;
		while(head)
		{
			count++;
			head=head->next;
		}
		return count;
	}
	Node *substracthelper(Node *ln,Node *sn, bool& borrow)
	{if(ln==NULL&&sn==NULL)
	return NULL;
	Node *previous=substracthelper(ln?ln->next:NULL,sn?sn->next:NULL,borrow);
	int d1=ln->data;
	int d2=sn->data;
	if(borrow)
	{
		d1--;
		borrow=false;
	}
	if(d1<d2)
	{
		d1=d1+10;
		borrow=true;
	}
	Node *curr=new Node;
	curr->data=d1-d2;
	curr->next=previous;
	
	return curr;
	}
	Node* substract(Node* h1,Node* h2)
	{
		int len1=calclength(h1);
		int len2=calclength(h2);
		Node *ln=NULL,*sn=NULL;
		Node *temp=h1,*temp1=h2;
		if(len1!=len2)
		{
			ln=len1>len2?temp:temp1;
			sn=len1>len2?temp1:temp;
			for(int i=0;i<abs(len1-len2);i++)
			{
			push(&sn,0);
			}
		}
		else
		{
			while(h1&&h2)
			{
				if(h1->data!=h2->data)
				{
					ln=h1->data>h2->data?temp:temp1;
					sn=h1->data>h2->data?temp1:temp;
					break;
				}
				h1=h1->next;
				h2=h2->next;
			}
			
		}
		bool borrow=false;
		return substracthelper(ln,sn,borrow);
	}
int main()
{Node *head =NULL;
push(&head,0);
push(&head,0);
push(&head,1);
Node *head1=NULL;
push(&head1,1);
push(&head1,0);
push(&head1,1);
printlist(head);
printlist(head1);
Node *ptr=substract(head,head1);
if(ptr==NULL)
cout<<0;
printlist(ptr);
}
