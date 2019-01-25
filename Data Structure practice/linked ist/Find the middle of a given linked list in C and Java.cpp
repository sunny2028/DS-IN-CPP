#include<iostream>https://https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
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
void swaper(node **head)
{ node *mid=*head,*final=*head;
while(final->next&&final!=NULL)
{mid=mid->next;
final=final->next->next;
if(!final)
    break;


}
cout<<mid->data;
}

int main()
{node *head=NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);
display(head);
swaper(&head);
}
