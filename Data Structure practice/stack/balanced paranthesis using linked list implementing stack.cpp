#include<iostream>
using namespace std;
struct Node
{
	char data;
	Node *next;
};
void push(Node **head,char data)
{
	Node *newnode=new Node;
	newnode->data=data;
	newnode->next=*head;
	*head=newnode;
}
void pop(Node **head)
{if(head==NULL)
return;
	Node *temp=*head;
	*head=(*head)->next;
	delete temp;
}
char peek(Node *head)
{if(head==NULL)
  return ' ';
	return head->data;
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
	
int length(char *arr)
	{int i=0,count=0;
		while(arr[i])
		{
			count++;
			i++;
		}
		return count;
	}
	
int check(char *arr)
	{ int i=0;
	Node *head=NULL;
	if(length(arr)%2!=0)
	return 0;
		while(arr[i])
		{
			if(arr[i]=='{'||arr[i]=='['||arr[i]=='(')
			push(&head,arr[i]);
			else if(arr[i]=='}')
			{
				if(peek(head)!='{')
				return 0;
				else
				pop(&head);
			}
			else if(arr[i]==')')
			{
				if(peek(head)!='(')
				return 0;
				else
				pop(&head);
			}
			else if(arr[i]==']')
			{
				if(peek(head)!='[')
				return 0;
				else
				pop(&head);
			}
			else 
			return 0;
			i++;
		}
		if(head==NULL)
		return 1;
		else
		return 0;
	}
	
int main()
{Node *head =NULL;
char *arr ="{[]}]]";
cout<<check(arr);
}
