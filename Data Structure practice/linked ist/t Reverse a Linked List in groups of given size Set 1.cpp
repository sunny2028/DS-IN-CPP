#include<iostream>//time comlexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
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
node *rev(node *head,int k)
{node *curr=head,*prev=NULL,*next=NULL;
int count=0;
while(curr&&count<k)
{next=curr->next;
curr->next=prev;
prev=curr;
curr=next;
count++;
}
if(next!=NULL)
{
head->next=rev(next,k);

}
return prev;
}

int main()
{
    node *start = NULL;
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
    printList(start);
    node *head=rev(start,2);
    printList(head);
    return 0;
}
