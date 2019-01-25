#include<bits/stdc++.h>//https://www.geeksforgeeks.org/sort-linked-list-already-sorted-absolute-values/
using namespace std;//time complexity:O(n) auxiliary space:O(1)
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
void delete(node **head,int k)
{node *temp=*head;
node *ptr=NULL:
while(temp)
{if(temp->data==k)
ptr=temp;
temp=temp->next;
}
if(ptr!=NULL&&ptr->next!=NULL)
{ptr->data=ptr->next->data;
node *abc=ptr->next;
ptr->next=ptr->next->next;
delete abc;
}
temp=*head;
if(ptr!=NULL&&ptr->next==NULL)
{while(temp->next!=ptr)
temp=temp->next;
temp->next=NULL;
}
}
int main()
{node *head=NULL;
push(&head,3);
push(&head,7);
push(&head,3);
push(&head,2);
push(&head,1);
display(head);
delete(&head);
display(head);

}
