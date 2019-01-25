#include<bits/stdc++.h>
using namespace std;
struct node
{int data;
node *next;
int flag=0;
};
void check(node *head,node *head1)
{node *temp=head,*temp1=head1;
while(temp)
{temp->flag=1;
temp=temp->next;
}
while(temp1)
{if(temp->flag==1)
{cout<<temp->data;
return;
}
temp1=temp1->next;
}
cout1<<"not found";
}
int main()
{node *newnode;
node *head=new node;
head->data=1;
node *head1=new node;
head1->data=2;
newnode=new node;
newnode->data=3;
head->next=newnode;
newnode=new node;
newnode->data=4;
head->next->next=newnode;
newnode=new node;
newnode->data=5;
head->next->next->next=newnode;
head1->next=newnode;
newnode=new node;
newnode->data=6;
head->next->next->next->next=newnode;
head1->next->next=newnode;
check(head,head1);
return 0;
}
