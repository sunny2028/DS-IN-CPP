#include<bits/stdc++.h>https://https://www.geeksforgeeks.org/select-a-random-node-from-a-singly-linked-list/
using namespace std;//time complexity:O(n)
struct node
{int data;
node *next;
};
void push(node **head,int data)
{node *newnode=new node;
newnode->data=data;a
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

int select(node *head)
{node *temp=head;
srand(time(NULL));
int result=temp->data;
for(int i=2;temp!=NULL;i++)
{if(rand()%i==0)
result=temp->data;

temp=temp->next;


}
return result;


}
int main()
{node *head=NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);
display(head);
cout<<select(head);
}
