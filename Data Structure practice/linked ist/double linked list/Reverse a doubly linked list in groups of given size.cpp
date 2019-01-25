#include <bits/stdc++.h>
  
using namespace std;
  
// a node of the doubly linked list
struct Node {
    int data;
    Node *next, *prev;
};
  
// function to get a new node
Node* getNode(int data)
{
    // allocate space
    Node* new_node = (Node*)malloc(sizeof(Node));
  
    // put in the data
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}
  
// function to insert a node at the beginging
// of the Doubly Linked List
void push(Node** head_ref, Node* new_node)
{
    // since we are adding at the begining,
    // prev is always NULL
    new_node->prev = NULL;
  
    // link the old list off the new node
    new_node->next = (*head_ref);
  
    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
  
    // move the head to point to the new node
    (*head_ref) = new_node;
}
 
// function to reverse a doubly linked list
// in groups of given size
Node* revListInGroupOfGivenSize(Node* head, int k)
{if(!head)
return NULL;
Node *curr=head;
Node *temp;
int count=0;
static Node *c=NULL;
while(curr&&count<k)
{
	temp=curr->prev;
	curr->prev=curr->next;
	curr->next=temp;
	curr=curr->prev;
	count++;
}
temp->prev->prev=c;
c=head;
head->next=revListInGroupOfGivenSize(curr,k);
return temp->prev;
}
 
// Function to print nodes in a
// given doubly linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
  
// Driver program to test above
int main()
{
    // Start with the empty list
    Node* head = NULL;
  
    // Create doubly linked: 10<->8<->4<->2 
    push(&head, getNode(8));
    push(&head, getNode(7));
    push(&head, getNode(6));
    push(&head, getNode(5));
     push(&head, getNode(4));
      push(&head, getNode(3));
       push(&head, getNode(2));
        push(&head, getNode(1));
     
    int k = 3;
  
    cout << "Original list: ";
    printList(head);
  
    // Reverse doubly linked list in groups of 
    // size 'k'
    head = revListInGroupOfGivenSize(head, k);
  
    cout << "\nModified list: ";
    printList(head);
  
    return 0;
}

