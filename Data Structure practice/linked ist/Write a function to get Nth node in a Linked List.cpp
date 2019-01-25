#include<iostream>https://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/
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
void swaper(node **head,int count)
{ node *temp=*head;
   int k=0;
   while(k<count&&temp)
   {k++;
   temp=temp->next;
   }
   if(temp==NULL)
   {cout<<"not present";
   }
   else
   {
   cout<<temp->data;
   }
}

int main()
{node *head=NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);
push(&head,6);
display(head);
swaper(&head,0);
}
