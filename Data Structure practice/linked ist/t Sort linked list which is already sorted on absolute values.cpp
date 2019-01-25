#include<bits/stdc++.h>//https://www.geeksforgeeks.org/sort-linked-list-already-sorted-absolute-values/
using namespace std;//time complexity:O(n) auxiliary space:O(1)
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
void sort(node **head)
{node* temp=(*head)->next;
node *q=*head;
node *h=NULL;
while(temp)
{if((temp->data)<0)
{q->next=temp->next;
h=temp->next;
temp->next=*head;
*head=temp;
temp=h;
}
else
{q=temp;
temp=temp->next;
}
}
}
int main()
{node *head=NULL;
push(&head,9);
push(&head,7);
push(&head,-3);
push(&head,-2);
push(&head,-1);
display(head);
sort(&head);
display(head);

}
