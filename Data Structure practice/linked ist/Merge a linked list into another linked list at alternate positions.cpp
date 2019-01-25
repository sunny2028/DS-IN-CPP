#include<iostream>//time complexity:O(m+n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/merge-a-linked-list-into-another-linked-list-at-alternate-positions/
struct node{
int data;
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
void merge(node *p,node **q)
{node *pcurr=p,*qcurr=*q;
node *pnext=NULL,*qnext=NULL;
while(pcurr&&qcurr)
{pnext=pcurr->next;
qnext=qcurr->next;

pcurr->next=qcurr;
qcurr->next=pnext;

pcurr=pnext;
qcurr=qnext;
}
*q=qcurr;
}
int main()
{
     struct node *p = NULL, *q = NULL;
     push(&p, 3);
     push(&p, 2);
     push(&p, 1);
     display(p);
     push(&q, 8);
     push(&q, 7);
     push(&q, 6);
     push(&q, 5);
     push(&q, 4);
     display(q);
     merge(p, &q);
     display(p);
     display(q);
     return 0;
}
