#include<iostream>//time comlexity:O(n) auxiliary space:O(1)
using namespace std;//https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/
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
void swap(int *a,int *b)
{int temp;
temp=*a;
*a=*b;
*b=temp;
}
void seggregate(node **head)
{/*node *temp=*head;int pos=0;node *q,*w;
while(temp)
{pos++;
    if((temp->data)%2!=0)
     {q=temp;
     break;
     }
}
int count=1;
temp=*head;
while(temp)
{if((temp->data)%2==0&&count>pos)
  {w=q;
  while(w!=temp)
  {swap((w->data),(temp->data));
        w=w->next;

  }
  q=q->next;
  }
  count++;
  temp=temp->next;
}*/
node *temp=*head,*temp1=*head,*prev ;int count=0,i=0,flag=0;
while(temp->next)
{count++;
    temp=temp->next;
}
while(i<count&&temp1->data%2!=0)
{temp->next=temp1;
temp1=temp1->next;
temp->next->next=NULL;
temp=temp->next;
i++;
}
while(i<count)
{

    if(temp1->data%2==0&&flag==0)
    { flag=1;

        *head=temp1;
        prev=temp1;
        temp1=temp1->next;
    }
    else if(temp1->data%2==0&&flag==1)
    {

        prev->next=temp1;
        prev=temp1;
        temp1=temp1->next;
    }
    else
    {

        prev->next=temp1->next;
    temp1->next=NULL;
    temp->next=temp1;
    temp=temp->next;
    temp1=prev->next;
    }
    i++;
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
    seggregate(&start);
    printList(start);
    return 0;
}
