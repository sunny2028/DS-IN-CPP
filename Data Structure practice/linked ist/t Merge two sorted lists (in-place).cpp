#include<iostream>//https://www.geeksforgeeks.org/merge-two-sorted-lists-place/
using namespace std;//time complexit=O(n1+n2) auxiliary space=O(1)
struct node{
int data;
node *next;
};
void push(node **tail,node **head,int data)
{node *newnode=new node;
newnode->data=data;
newnode->next=NULL;
if(*head==NULL)
{*head=newnode;
*tail=newnode;}
else
{
(*tail)->next=newnode;
*tail=newnode;
}
}
void print(node *h)
{while(h!=NULL)
{cout<<h->data<<" ";
h=h->next;
}
cout<<"\n";
}
node *merge(node *h1,node *h2)
{
if(h1==NULL)
return h2;
if(h2==NULL)
return h1;
if(h1->data<=h2->data)
{h1->next=merge(h1->next,h2);
return h1;
}
else
{
h2->next=merge(h1,h2->next);
return h2;
}
}
int main()
{node *head1=NULL,*tail1=NULL;
push(&tail1,&head1,1);
push(&tail1,&head1,4);
push(&tail1,&head1,6);
push(&tail1,&head1,8);
push(&tail1,&head1,10);
push(&tail1,&head1,13);
print(head1);
node *head2=NULL,*tail2=NULL;
push(&tail2,&head2,2);
push(&tail2,&head2,3);
push(&tail2,&head2,5);
push(&tail2,&head2,7);
push(&tail2,&head2,17);
push(&tail2,&head2,19);
print(head2);
node *res=merge(head1,head2);
print(res);
}
