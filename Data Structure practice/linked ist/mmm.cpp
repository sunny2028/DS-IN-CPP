#include<iostream>https://https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
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
void show(node *head,node *head1)
{node *newnode=new node;
node *head2=NULL;
while(head&&head1)
{if(head->data<head1->data)
{if(head2==NULL)
   {newnode->data=head->data;
    newnode->next=NULL;
 head2=newnode;
   }
   else
   { newnode->data=head->data;
   newnode->next=NULL;
   head2->next=newnode;
  head2=newnode;
   }
}
else
{{if(head2==NULL)
   {newnode->data=head1->data;
    newnode->next=NULL;
    head2=newnode;
   }
   else
   {head2->next=newnode;
   newnode->data=head1->data;
   newnode->next=NULL;
      head2->next=newnode;
   head2=newnode;
   }
}
head=head->next;
head1=head1->next;
}
if(head)
{while(head)
{newnode->data=head->data;
newnode->next=NULL;
head2->next=newnode;
head2=newnode;
head=head->next;
}
}

}
int main()
{node *head=NULL;
push(&head,1);
push(&head,5);
push(&head,7);
push(&head,10);
display(head);
node *head1=NULL;
push(&head1,2);
push(&head1,3);
push(&head1,4);
push(&head1,6);
display(head1);
show(head,head1);
