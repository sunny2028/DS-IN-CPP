#include<iostream>//time comlexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/
struct node
{
    int data;
    node *next;
};
void lastSwap(node **head)
{node *temp=*head,*q;
while(temp->next)
{q=temp;
temp=temp->next;
}
q->next=NULL;
temp->next=*head;
*head=temp;
}
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
int main()
{
    node *start = NULL;

    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
    printList(start);
    lastSwap(&start);
    printList(start);
    return 0;
}
