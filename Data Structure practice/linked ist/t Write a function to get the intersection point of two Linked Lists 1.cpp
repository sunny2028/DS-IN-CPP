#include<bits/stdc++.h>//Time Complexity: O(m*n) Auxiliary Space: O(1)
using namespace std;//https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
struct node
{int data;
node *next;
};
void check(node *head,node *head1)
{node *temp=head,*temp1=head1;
while(temp)
{temp1=head1;
while(temp1)
{if(temp1==temp)
{cout<<temp->data;
return;
}
temp1=temp1->next;
}
temp=temp->next;
}
cout<<"not found";
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
head1->next->next->next=NULL;
check(head,head1);
return 0;
}
