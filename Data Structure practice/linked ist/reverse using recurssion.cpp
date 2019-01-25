#include<iostream>
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
	void reverse1(Node *curr,Node *prev,Node **head)
{
	if(curr->next==NULL)
	{curr->next=prev;
	*head=curr;
	return;
    }
	Node *next=curr->next;
	curr->next=prev;
	
	reverse1(next,curr,head);
}
void reverse( Node **head)
{
	if(head==NULL)
	{
		return ;
    }
  reverse1(*head,NULL,head);
}

int main()
{Node *head =NULL;
push(&head,0);
push(&head,6);
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);
printlist(head);
//deleteeven(&head);
reverse(&head);
printlist(head);
}
