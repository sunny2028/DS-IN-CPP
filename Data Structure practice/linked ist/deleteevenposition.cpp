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
void deleteeven(Node **head)
{Node *curr=*head;e
Node * prev;
while(curr!=NULL)
{prev =curr;
curr=curr->next;
if(!curr)
break;
Node * temp=curr;
	prev->next=curr->next;
	curr=prev->next;
	delete temp;
}	
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
deleteeven(&head);
printlist(head);
}
