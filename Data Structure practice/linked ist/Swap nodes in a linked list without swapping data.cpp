#include<iostream>//https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/
using namespace std;//Time complexity:O(n)
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
void swaper(node **head,int x,int y)
{ if(x==y)
return;
    node *currx=*head,*prevx=NULL,*curry=*head,*prevy=NULL;
while(currx&&currx->data!=x)
{prevx=currx;
currx=currx->next;
}
while(curry&&curry->data!=y)
{prevy=curry;
curry=curry->next;
}
if(currx==NULL||curry==NULL)
{
 cout<<"not present\n";
 return;

}
   if(prevx!=NULL)
   {

       prevx->next=curry;
   }
   else
   {
       *head=curry;

   }
   if(prevy!=NULL)
   {

       prevy->next=currx;
   }
   else
   {
    *head=currx;
   }
   node *temp;
   temp=currx->next;
   currx->next=curry->next;
   curry->next=temp;


    /*
node *p,*q,*temp=head,*e=NULL,*r,*t;
while(temp!=NULL)
{if(temp->data==j)
{r=e;
p=temp;
}
if(temp->data==k)
{t=e;
q=temp;
}
e=temp;
temp=temp->next;
}
r->next=q;
t->next=p;
node *v=p->next;
p->next=q->next;
q->next=v;*/
}

int main()
{node *head=NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);
push(&head,6);
display(head);
swaper(&head,5,4);
display(head);
}
