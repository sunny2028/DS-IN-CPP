#include<iostream>//time complexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/delete-n-nodes-after-m-nodes-of-a-linked-list/
struct node{
int data;
node *next;
};
void push(node **head,int data)
{node *newnode=new node;
newnode->data=data;
newnode->next=*head;
*head=newnode;
}
void display(node *head)
{node *temp=head;
while(temp!=NULL)
{cout<<temp->data<<" ";
temp=temp->next;
}
cout<<"\n";
}
void del(node **head,int m,int n)
{node *temp=*head,*p;
int count;
while(temp)
{for(count=1;count<m&&temp!=NULL;count++)
    temp=temp->next;
     if(!temp)
        return;
    p=temp->next;
    for(count=1;count<=n&&p!=NULL;count++)
    {node *t=p->next;
    delete p;
    p=t;
    }
    temp->next=p;
    temp=p;
}


}
int main()
{node *head=NULL;
    push(&head, 11);
    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    display(head);
    del(&head,2,3);
    display(head);

}
