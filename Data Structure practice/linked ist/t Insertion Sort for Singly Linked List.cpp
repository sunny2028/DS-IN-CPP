#include<iostream>//time comlexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/
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
void sortedinsert(node **head,node *newnode)
{node *current;
if(*head==NULL||(*head)->data>newnode->data)
{newnode->next=*head;
*head=newnode;
}
else
{current=*head;
    while(current->next!=NULL&&current->next->data<newnode->data)
{current=current->next;
}
newnode->next=current->next;
current->next=newnode;
}
}
void insertionsort(node **head)
{
node *current=*head;
node *start=NULL;
while(current)
{node *next=current->next;
sortedinsert(&start,current);
current=next;
}
*head=start;

}

int main()
{
    node *start = NULL;
    push(&start, 5);
    push(&start, 20);
    push(&start, 4);
    push(&start, 3);
    push(&start, 30);

    printList(start);
    insertionsort(&start);
    printList(start);
    return 0;
}
