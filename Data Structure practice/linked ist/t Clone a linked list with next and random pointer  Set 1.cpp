#include<iostream>//time comlexity:O(n) auxiliary space:O(n)
using namespace std;//https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
struct node
{
    int data;
    node *next;
    node *arbt;
};
node *header=NULL;
void push(struct node** head_ref, int new_data)
{
    node* new_node =new node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void arbtalloc(node **head)
{node *temp=*head;
while(temp->next->next)
{

    temp->arbt=temp->next->next->arbt;
}
temp->arbt=*head;
temp->next->arbt=(*head)->next;

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
void push1(node **head,int data)
{node *newnode=new node;
newnode->data=data;
    if(*head=NULL)
    {*head=newnode;
    newnode->next=NULL;
    header=*head;
    }
    else
    {(*head)->next=newnode;
    newnode->next=NULL;
    *head=newnode;
    }

}
void clone(node *head)
{int arr[12],i=0;
node *temp=head;
while(temp)
{arr[i]=temp;
arr[i+1]=(temp->next);
i+=2;
}
temp=head;
node *head1=NULL;
node *p;
while(temp)
{

    push1(&head1,temp->data);
    temp=temp->next;

}
temp=head;
node *temp1=header;
p=temp;
while(p)
{p=temp->next;
temp->next=temp1;
   temp1->arbt=temp;
   temp1=temp1->next;
   temp=p;

}
temp1=header;
temp=head;
while(temp1)
{

    temp1->arbt=temp1->arbt->arbt->next;
    temp1=temp1->next;
}
temp=head;
i=0;
while(temp)
{temp->next=arr[i+1];
i++;
temp=temp->next;
}
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
    arbtalloc(&start);
    clone(&start);
    printList(start);
    printList(header);
    return 0;
}
