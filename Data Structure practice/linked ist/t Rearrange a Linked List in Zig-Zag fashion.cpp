#include<bits/stdc++.h>//https://www.geeksforgeeks.org/linked-list-in-zig-zag-fashion/
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
void zigzag(node *head)
{node *temp=head;
bool flag=true;
while(temp->next)
{if(flag)
{if(temp->data>temp->next->data)
swap(temp->data,temp->next->data);
}
else
{if(temp->data<temp->next->data)
swap(temp->data,temp->next->data);
}
temp=temp->next;
flag=!flag;
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
zigzag(head);
display(head);
}
