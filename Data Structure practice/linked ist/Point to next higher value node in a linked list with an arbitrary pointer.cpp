#include<iostream>//time comlexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/point-to-next-higher-value-node-in-a-linked-list-with-an-arbitrary-pointer/s
struct node
{
    int data;
    node *next;
    node *arbt=NULL;
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
void arbit(node *head)
{node *current=head;

while(current)
{node *temp=head;
int k=1000;
while(temp)
{
    if(temp->data>current->data&&temp->data<k)
{k=temp->data;
current->arbt=temp;
}
temp=temp->next;
}
if(k==1000)
{
    current->arbt=head;
}
current=current->next;
}
}
void printarbt(struct node *head)
{
    while (head != NULL)
    {
       cout<<head->data<<" "<<head->arbt->data<<"\n";
       head = head->next;
    }
    cout<<"\n";
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
    arbit(start);
    printarbt(start);
    return 0;
}
