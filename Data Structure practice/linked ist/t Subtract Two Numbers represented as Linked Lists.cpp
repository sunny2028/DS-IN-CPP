#include<bits/stdc++.h>//https://www.geeksforgeeks.org/decimal-equivalent-of-binary-linked-list/
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
int callength(node *head)
{int count=0;
while(head)
{count++;
head=head->next;
}
return count;
}
int callength1(int num)
{int count=0;
while(num)
{count++;
num=num/10;
}
return count;
}
void substract(node *head,node *head1)
{int len=callength(head);
int len1=callength(head1);
int i=len-1,j=len1-1;
node *temp=head;
int num=0,num1=0;
while(temp)
{num=num+(temp->data)*pow(10,i);
//cout<<num<<"ese";
temp=temp->next;
i--;
}
temp=head1;
while(temp)
{num1=num1+(temp->data)*pow(10,j);
temp=temp->next;
j--;
}
int res=abs(num-num1);
int len2=callength1(res);
int max=len>len1?len:len1;
node *head2=NULL;
for(i=0;i<max;i++)
{int rem=res%10;
res=res/10;
push(&head2,rem);
}
display(head2);
}
int main()
{node *head=NULL;
node* head1=NULL;
push(&head,0);
push(&head,0);
push(&head,1);
push(&head1,1);
display(head);
display(head1);
substract(head,head1);

}
