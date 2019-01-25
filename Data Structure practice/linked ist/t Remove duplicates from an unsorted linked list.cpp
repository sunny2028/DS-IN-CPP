#include<bits/stdc++.h>//Time Complexity: O(n^n) Auxiliary Space: O(1)
using namespace std;//https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
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
while(temp)
{tempp=temp;
while(tempp->next)
{ if(temp->data==tempp->next->data)
    {q=tempp->next;
    tempp->next=tempp->next->next;
    delete q;
    }
    else
        tempp=tempp->next;
}
temp=temp->next;
}
}
void printlist(struct node *node1)
{
    while (node1!=NULL)
    {
       cout<<node1->data<<" ";
       node1 = node1->next;
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
