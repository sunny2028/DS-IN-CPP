#include<bits/stdc++.h>//https://www.geeksforgeeks.org/add-1-number-represented-linked-list/
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
{cout<<temp->data<<" ";
temp=temp->next;
}
cout<<"\n";
}
int checkpalindrome(node *head)
{string s;
node *temp=head;
while(temp)
{s.append()


}



}
int main()
{node *head=NULL;
push(&head,"a");
push(&head,"bc");
push(&head,"dd");
push(&head,"cb");
push(&head,"a");
display(head);
checkpalindrome(head);

}
