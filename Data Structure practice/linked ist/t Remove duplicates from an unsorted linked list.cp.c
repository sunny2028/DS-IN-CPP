#include<bits/stdc++.h>//Time Complexity: O(n) Auxiliary Space: O(1)
using namespace std;//https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
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
void print(node *head)
{node *temp=head;
node *q;
node *tempp;
while(temp->next)
{tempp=temp->next;
q1=temp;
while(tempp)
{if(temp->data==tempp->data)
{q=tempp->next;
delete q1->next;
tempp=q;
}
q1=tempp;
tempp=tempp->next;
}
temp=temp->next;
}
}
int main()
{node *head=NULL;
   push(&head, 12);
    push(&head, 11);
    push(&head, 12);
    push(&head, 21);
    push(&head, 41);
    push(&head, 23);
    push(&head, 21);
    print(head);
    printlist(head);
}
