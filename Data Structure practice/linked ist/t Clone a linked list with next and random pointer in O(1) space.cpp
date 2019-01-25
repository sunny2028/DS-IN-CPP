#include<iostream>//time comlexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/clone-linked-list-next-random-pointer-o1-space/
struct node
{
    int data;
    node *next;
    node *arbt;
    node(int x)
    {
        data=x;
        next=NULL;
    arbt=NULL;
    }
};
void push(struct node** head_ref, int new_data)
{
    node* new_node =new node(new_data);
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void arbtalloc(node **head)
{node *temp=*head;
while(temp->next->next)
{

    temp->arbt=temp->next->next;
    temp=temp->next;
}
temp->arbt=*head;
temp->next->arbt=(*head)->next;

}
void printList(struct node *head)
{
    while (head != NULL)
    {
       cout<<head->data<<" "<<head->arbt->data<<"\n";
       head = head->next;
    }
    cout<<"\n";
}
node *clone(node *head)
{node *temp=head;
node *p;
while(temp)
{p=temp->next;
temp->next=new node(temp->data);
temp->next->next=p;
temp=temp->next->next;
}
temp=head;
while(temp)
{temp->next->arbt=temp->arbt->next;
temp=temp->next?temp->next->next:temp->next;
}
temp=head;
node *temp1=head->next;
node *abc=temp1;
while(temp&&temp1)
{temp->next=temp->next->next;
temp1->next=temp1->next?temp1->next->next:temp1->next;
temp=temp->next;
temp1=temp1->next;
}
return abc;
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
    arbtalloc(&start);
    printList(start);
    node* abc=clone(start);
    printList(start);
    printList(abc);
    return 0;
}
