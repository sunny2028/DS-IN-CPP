#include<iostream>//time comlexity:O(n) auxiliary space:O(n)
using namespace std;//https://www.geeksforgeeks.org/alternating-split-of-a-given-singly-linked-list/
struct node
{
    int data;
    node *next;
};
void push(struct node** head,node **tail, int data)
{
    node* newnode =new node;
    newnode->data  = data;
    if(*head==NULL)
    {newnode->next=*head;
    *head=newnode;
    *tail=newnode;
    }
    else
    {(*tail)->next=newnode;
    newnode->next=NULL;
    *tail=newnode;
    }
}
void printList(struct node *head)
{
    while (head != NULL)
    {
       cout<<head->data<<" ";
       head = head->next;
    }
    cout<<"\n";
}
void check(node *head)
{node dummy,dummy1;
node *taill=NULL;
node *taill1=NULL;
node *temp=head;
node *tail=&dummy;
node *tail1=&dummy1;
dummy.next=NULL;
dummy1.next=NULL;
while(temp&&temp->next)
{push(&(tail->next),&taill,temp->data);
tail=tail->next;
temp=temp->next;
push(&(tail1->next),&taill1,temp->data);
tail1=tail1->next;
temp=temp->next;
}
if(temp)
{push(&(tail->next),&taill,temp->data);
tail=tail->next;}
tail->next=NULL;
tail1->next=NULL;
printList(dummy.next);
printList(dummy1.next);
}
int main()
{
    node *start = NULL;
    node *tail=NULL;
    push(&start,&tail, 6);
    push(&start,&tail, 5);
    push(&start,&tail, 4);
    push(&start,&tail, 3);
    push(&start,&tail, 2);
    push(&start,&tail,1);
    printList(start);
    check(start);
    return 0;
}
