#include<bits/stdc++.h>//time comlexity:O(n) auxiliary space:O(n)
using namespace std;//https://ide.geeksforgeeks.org/1eGSEy
struct node
{
    int data;
    node *next;
};
void push(struct node** head_ref, int new_data)
{
    node* new_node =new node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node *head)
{
    while (head != NULL)
    {
       cout<<head->data<<" ";
       head = head->next;
    }
    cout<<"\n";
}
void rearrange(node *head)
{vector<node *>v;
node *curr=head;
while(curr)
{v.push_back(curr);
curr=curr->next;
}
int l=v.size();
int i;
node *temp=head;
for(i=0;i<l/2;i++)
{if(i!=0)
    {
    temp->next=v[i];
    temp=temp->next;

    }
    temp->next=v[l-i-1];
    temp=temp->next;

}
if(l%2==1)
{temp->next=v[i];
temp=temp->next;
}
temp->next=NULL;
}
int main()
{
    node *start = NULL;
    push(&start, 5);
    push(&start, 6);
    push(&start, 20);
    push(&start, 4);
    push(&start, 3);
    push(&start, 30);
    printList(start);
    rearrange(start);
    printList(start);
    return 0;
}
