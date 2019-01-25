#include<iostream>//https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/
using namespace std;//time complexity:O(n)
struct node
{int data;
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
node *merge(node *a,node *b)
{if(a==NULL)
return b;
if(b==NULL)
return a;
if(a->data<b->data)
{a->next=merge(a->next,b);
return a;
}
else
{
b->next=merge(a,b->next);
return b;
}
}
node* mergesort(node *arr[],int last)
{
while(last!=0)
{int i=0,j=last;
while(i<j)
{arr[i]=merge(arr[i],arr[j]);
i++;
j--;
if(i>=j)
last=j;
}
}
return arr[0];
}
int main()
{node *head=NULL;
node *head1=NULL;
node *head2=NULL;
push(&head,5);
push(&head,4);
push(&head,1);
push(&head1,9);
push(&head1,3);
push(&head1,2);
push(&head2,8);
push(&head2,7);
push(&head2,6);
node *arr[3];
arr[0]=head;
arr[1]=head1;
arr[2]=head2;
node *head3=mergesort(arr,2);
display(head3);
}
