#include<bits/stdc++.h>//https://www.geeksforgeeks.org/move-occurrences-element-end-linked-list/
using namespace std;//time complexity:O(n) auxiiary space:O(1)
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
void moveleft(node *head,int key)
{node *pcrawl=head,*pkey=head;
while(pcrawl)
{if(pcrawl!=pkey&&pcrawl->data!=key)
{pkey->data=pcrawl->data;
pcrawl->data=key;
pkey=pkey->next;
}
if(pkey->data!=key)
{pkey=pkey->next;
}
pcrawl=pcrawl->next;
}

}
int main()
{node *head=NULL;
push(&head,1);
push(&head,1);
push(&head,0);
push(&head,1);
display(head);
moveleft(head,1);
display(head);
}
