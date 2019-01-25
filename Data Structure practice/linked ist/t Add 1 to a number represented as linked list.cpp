#include<bits/stdc++.h>//https://www.geeksforgeeks.org/add-1-number-represented-linked-list/
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
void addone(node *head)
{vector<int>v;
node *temp=head;
while(temp)
{v.push_back(temp->data);
temp=temp->next;
}
int l=v.size();
temp=head;
int n,i;
int carry1=1,g;
for( i=0;i<l-1;i++)
{n=v[l-i-1]+carry1;
if(n>=10)
{int g=n%10;
carry1=n/10;
v[l-i-1]=g;
}
else
{carry1=0;
v[l-i-1]=n;
}
}
v[l-i-1]=v[l-i-1]+carry1;
for(int i=0;i<l;i++)
cout<<v[i];
}
int main()
{node *head=NULL;
push(&head,9);
push(&head,9);
push(&head,9);
push(&head,9);
push(&head,9);
display(head);
addone(head);

}
