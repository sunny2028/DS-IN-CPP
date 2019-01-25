#include<bits/stdc++.h>//Time Complexity: O(n) Auxiliary Space: O(1)
using namespace std;//https://www.geeksforgeeks.org/print-reverse-of-a-linked-list-without-actually-reversing/
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
void printreverse(node *head)
{if(head==NULL)
return;
printreverse(head->next);
cout<<head->data<<" ";
}
int main()
{node *head=NULL;
push(&head,4);
push(&head,3);
push(&head,2);
push(&head,1);
printreverse(head);
return 0;
}
