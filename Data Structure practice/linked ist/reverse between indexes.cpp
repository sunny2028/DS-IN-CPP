#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *reverse(node *head,node *temp)
{
	node *prev=NULL;
	node *curr=head;
	while(curr!=temp)
	{ node *next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}
void push(node **head,int data)
{
	node *newnode =new node;
	newnode->data=data;
	newnode->next=*head;
	*head=newnode;
}
void printlist(node *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
cout<<"\n";
}
void reverselist(node **head,int i,int j,int n)
{
	if(j<i||j>=n)
	return;
	node *curr=*head,*a,*b;
	int count=0;
	while(1)
	{if(i==0)
	{
		while(count<j)
		{
			count++;
			curr=curr->next;
		}
		node *temp=curr->next;
		node *h=reverse(*head,temp);
		(*head)->next=temp;
		*head=h;
		break;
		
	}
	else
	{   while(curr)
		{if(count==i-1)
		a=curr;
		if(count==j+1)
	     {
			b=curr;
		    break;
	    }
		curr=curr->next;
		count++;
	   }
	   node *temp1=a->next;
	   a->next=reverse(temp1,b);
	   temp1->next=b;
	   break;
	}
  }	
}
int main()
{
node *head=NULL;
push(&head,1);	
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);
push(&head,6);
push(&head,7);
push(&head,8);
printlist(head);
reverselist(&head,0,3,8);
printlist(head);
}
