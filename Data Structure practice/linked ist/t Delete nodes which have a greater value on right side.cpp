#include<iostream>//time comlexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/
struct node
{
    int data;
    node *next;
};
void push(struct node** head_ref, int new_data)
{
    node* new_node =new node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
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

void rev(node **head)
{node *prev=NULL,*curr=*head,*next=NULL;
while(curr)
{next=curr->next;
curr->next=prev;
prev=curr;
curr=next;
}
*head=prev;
}

void delnext(node **head)
{
rev(head);
node *temp=*head;
int max=temp->data;
temp=temp->next;
node *q=*head;
while(temp)
{if(temp->data<max)
{q->next=temp->next;
delete temp;
temp=q->next;
}
else
{max=temp->data;
    q=temp;
    temp=temp->next;
}
}
rev(head);
}
int main()
{
    node *start = NULL;
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 7);
    printList(start);
    delnext(&start);
    printList(start);
    return 0;
}
