#include<bits/stdc++.h>https://https://www.geeksforgeeks.org/rearrange-a-linked-list-such-that-all-even-and-odd-positioned-nodes-are-together/
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
void combine(node *head)
{if(head==NULL)
return;
node *odd=head;
node *even=head->next;
node *evenfirst=even;
node *temp=head;

while(1)
{
if(!even||!(even->next))
{odd->next=evenfirst;
return;
}

odd->next=even->next;
odd=even->next;
if(odd->next==NULL)
{
even->next=NULL;
odd->next=evenfirst;
break;
}
even->next=odd->next;
even=odd->next;
}
}
int main()
{node *head=NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,6);
display(head);
combine(head);
display(head);
}
