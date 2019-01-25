#include<iostream>//time comlexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/
struct node
{
    int data;
    int data1;
    node *next;
};
void push(struct node** head_ref, int new_data,int data1)
{
    node* new_node =new node;
    new_node->data  = new_data;
    new_node->data1=data1;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node *head)
{
    while (head != NULL)
    {
       cout<<head->data<<" "<<head->data1<<"\n";
       head = head->next;
    }
    cout<<"\n";
}
void del(node **head)
{node *temp=*head,*p;
while(temp->next->next)
{if(temp->next->data==temp->data&&temp->next->data==temp->next->next->data||temp->next->data1==temp->data1&&temp->next->data1==temp->next->next->data1)
{p=temp->next;
temp->next=temp->next->next;
delete p;
}
else
temp=temp->next;
}
}
int main()
{node *head=NULL;
    push(&head, 40,5);
    push(&head, 20,5);
    push(&head, 10,5);
    push(&head, 10,8);
    push(&head, 10,10);
    push(&head, 3,10);
    push(&head, 1,10);
    push(&head, 0,10);
    del(&head);
    printList(head);
}
