#include<iostream>//time comlexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/reverse-alternate-k-nodes-in-a-singly-linked-list/
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
node *rev(node *head,int k,bool flag)
{node *curr=head,*prev=NULL,*next=NULL,*temp;
int count=0;
while(curr&&count<k&&flag==true)
{next=curr->next;
curr->next=prev;
prev=curr;
curr=next;
count++;
}
if(flag==false)
{prev=head;
while(head&&count<k)
{count++;
temp=head;
head=head->next;
}
next=head;
head=temp;
}
if(next!=NULL)
{flag=!flag;
head->next=rev(next,k,flag);

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
    bool flag=true;
    node *head=rev(start,3,flag);
    printList(head);
    return 0;
}
