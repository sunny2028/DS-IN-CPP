#include<iostream>//time comlexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list-by-changing-links/
struct node
{
    int data;
    struct node *next;
};
void pairWiseSwap(struct node **head)
{
    node *temp=*head,*nextt,*nexttt;
    (*head)=(*head)->next;
    while(true)
    {
    nextt=temp->next;
    nexttt=temp->next->next;
    nextt->next=temp;
    if(nexttt==NULL||nexttt->next==NULL)
    {temp->next=nexttt;
    break;
    }
        temp->next=nexttt->next;
    temp=nexttt;
    }
}
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =new node;
    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct node *nodde)
{
    while (nodde != NULL)
    {
       cout<<nodde->data<<" ";
       nodde = nodde->next;
    }
}
int main()
{
    struct node *start = NULL;

    /* The constructed linked list is:
     1->2->3->4->5 */

    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    cout<<"Linked list before calling  pairWiseSwap()\n";
    printList(start);

    pairWiseSwap(&start);

    cout<<"\nLinked list after calling  pairWiseSwap()\n";
    printList(start);

    return 0;
}
