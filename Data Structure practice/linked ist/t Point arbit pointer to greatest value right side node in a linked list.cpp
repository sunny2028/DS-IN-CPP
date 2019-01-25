#include<bits/stdc++.h>//https://www.geeksforgeeks.org/point-arbit-pointer-greatest-value-right-side-node-linked-list/
using namespace std;//time complexity:O(n) auxiliary space:O(1)
struct node
{int data;
node *next;
node *arbt=NULL;
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
void display1(node *head)
{node *temp=head;
while(temp->next!=NULL)
{cout<<temp->data<<"  "<<temp->arbt->data<<"\n";
temp=temp->next;
}
cout<<temp->data;
cout<<"\n";
}
void reverse1(node **head)
{node *prev=NULL;
node *next=NULL;
node *temp=*head;
while(temp)
{next=temp->next;
temp->next=prev;
prev=temp;
temp=next;
}
*head=prev;
}

void greatestarbt(node *head)
{node *start=head;
reverse1(&head);
node *maxi=head;
node *temp=head->next;
while(temp)
{
temp->arbt=maxi;
if(temp->data>maxi->data)
{maxi=temp;

}
temp=temp->next;
}

reverse1(&head);
}
int main()
{node *head=NULL;
push(&head,5);
push(&head,4);
push(&head,3);
push(&head,2);
push(&head,6);
display(head);
greatestarbt(head);
display1(head);

}
