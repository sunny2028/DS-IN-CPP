#include<bits/stdc++.h>//https://www.geeksforgeeks.org/check-linked-list-strings-form-palindrome/
using namespace std;//time complexity:O(n) auxiliary space:O(n)
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
void mergeLists(node *a,node * &b)
{node *prev=NULL;
while(a&&b)
{if(a->data>b->data)
{swap(a->data,b->data);
node *temp=b;
if(b->next&&b->data>b->next->data)
{b=b->next;
node *ptr=b;
while(ptr&&ptr->data<temp->data)
{prev=ptr;
ptr=ptr->next;
}
prev->next=temp;
temp->next=ptr;
}
}
a=a->next;
}

}
int main()
{
    node *a = NULL;
    push(&a, 10);
    push(&a, 8);
    push(&a, 7);
    push(&a, 4);
    push(&a, 2);

    node *b = NULL;
    push(&b, 12);
    push(&b, 3);
    push(&b, 1);
 display(a);
 display(b);
    mergeLists(a,b);
     display(a);
 display(b);
 }
