#include<iostream>//https://www.geeksforgeeks.org/decimal-equivalent-of-binary-linked-list/
using namespace std;//time complexity:O(n)
struct node
{int data;
node *next;
};
void push(node **head,int data)
{node *newnode=new node;
newnode->data=data;
newnode->next=*head;
*head=newnode;
}
void display(node *head)
{node *temp=head;
while(temp!=NULL)
{cout<<temp->data<<" ";
temp=temp->next;
}
cout<<"\n";
}
int show(node *head)
{int result=0;
while(head)
{result=(result*2)+head->data; //or result=(result<<1)+head->data;
head=head->next;
}
return result;
}
int main()
{
node *head=NULL;
push(&head,1);
push(&head,0);
push(&head,0);
push(&head,1);
push(&head,0);
display(head);
cout<<show(head);

}
