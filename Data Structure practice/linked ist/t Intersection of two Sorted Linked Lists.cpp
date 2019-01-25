#include<iostream>//time comlexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/
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
node *check(node *a,node *b)
{node dummy;
node *tail=&dummy;
dummy.next=NULL;
while(a!=NULL&&b!=NULL)
{if(a->data==b->data)
{push(&(tail->next),a->data);
tail=tail->next;
a=a->next;
b=b->next;
}
else if(a->data<b->data)
a=a->next;
else
b=b->next;
}
return (dummy.next);



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
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
    printList(start);
    push(&start1, 6);
    push(&start1, 4);
    push(&start1, 2);
    printList(start1);
    node *res=check(start,start1);
    printList(res);
    return 0;
}
