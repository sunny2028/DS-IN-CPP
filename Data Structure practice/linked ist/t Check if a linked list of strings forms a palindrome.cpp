#include<bits/stdc++.h>//https://www.geeksforgeeks.org/check-linked-list-strings-form-palindrome/
using namespace std;//time complexity:O(n) auxiliary space:O(n)
struct node
{string data;
node *next;
};
void push(node **head,string data)
{node *newnode=new node;
newnode->data=data;
newnode->next=*head;
*head=newnode;
}
void display(node *head)
{node *temp=head;
while(temp!=NULL)
{cout<<temp->data;
temp=temp->next;
}
cout<<"\n";
}
int checkpalindrome(node *head)
{string s="";
node *temp=head;
while(temp)
{s.append(temp->data);
temp=temp->next;
}
string p=s;
reverse(s.begin(),s.end());
if(s==p)
    return 1;
else return 0;

}
int main()
{node *head=NULL;
push(&head,"a");
push(&head,"bc");
push(&head,"dd");
push(&head,"cb");
push(&head,"a");
display(head);
int c=checkpalindrome(head);
if(c==0)
    cout<<"Not a Palindrome";
if(c==1)
    cout<<"Is a Palindrome";

}
