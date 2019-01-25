#include<bits/stdc++.h>//https://www.geeksforgeeks.org/length-longest-palindrome-list-linked-list-using-o1-extra-space/
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
int count(node *a,node *b)
{int count=0;
for(;a&&b;a=a->next,b=b->next)
if(a->data==b->data)
 count++;
 else
 break;
 return count;

}
int maxPalindrome(node *head)
{node *prev=NULL,*curr=head,*next=NULL;
int res=0;
while(curr)
{next=curr->next;
curr->next=prev;
res=max(res,2*count(prev,next)+1);
res=max(res,2*count(curr,next));
prev=curr;
curr=next;
}
return res;
}

int main()
{node *head=NULL;
push(&head,1);
push(&head,1);
push(&head,0);
push(&head,1);
display(head);
cout<<maxPalindrome(head);
}
