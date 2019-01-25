#include<iostream>//time comlexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/delete-alternate-nodes-of-a-linked-list/
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
void delnode(node *head)
{node *temp=head,*temp1;
while(temp&&temp->next)
{temp1=temp->next;
temp->next=temp->next->next;
delete temp1;
temp=temp->next;
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
int main()
{
    node *start = NULL;
      node *start1 = NULL;
       push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
    printList(start);
    delnode(start);
    printList(start);
    return 0;
}
