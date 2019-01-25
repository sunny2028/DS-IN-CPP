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
node *temp1;
while(temp->next)
{if(temp->data==temp->next->data)
{temp1=temp->next->next;
delete temp->next;
temp->next=temp1;
}
else
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
   push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);
    print(head);
    printlist(head);
}
