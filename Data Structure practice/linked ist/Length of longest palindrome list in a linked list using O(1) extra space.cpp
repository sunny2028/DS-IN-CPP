#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
int countcommon(Node *a,Node *b)
{int count=0;
	while(a&&b)
	{
		if(a->data==b->data)
		count++;
		a=a->next;
		b=b->next;
	}
	return count;
}
int maxPalindrome(Node *head)
{
	Node *curr=head,*prev=NULL,*next;
	int result=0;
	while(curr)
	{
	next=curr->next;
	curr->next=prev;
	result=max(result,2*countcommon(curr,next));
	result=max(result,2*countcommon(prev,next)+1);

	prev=curr;
	curr=next;
	}
	return result;
}
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
/* Drier program to test above functions*/
int main()
{
    /* Let us create a linked lists to test
       the functions
    Created list is a: 2->4->3->4->2->15 */
    Node *head = newNode(2);
    head->next = newNode(4);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(15);
 
    cout << maxPalindrome(head) << endl;
    return 0;
}
