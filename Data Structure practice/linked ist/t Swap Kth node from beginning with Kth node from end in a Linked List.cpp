// A C++ program to swap Kth node from beginning with kth node from end
#include <iostream>//https://www.geeksforgeeks.org/swap-kth-node-from-beginning-with-kth-node-from-end-in-a-linked-list/
#include <stdlib.h>//Time coplexity:O(n) auxiliary space O(1)
using namespace std;

// A Linked List node
struct Node
{
	int data;
	struct Node *next;
};

/* Utility function to insert a node at the beginning */
void push(struct Node **head_ref, int new_data)
{
	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Utility function for displaying linked list */
void printList(struct Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

/* Utility function for calculating length of linked list */
int countNodes(struct Node *s)
{
	int count = 0;
	while (s != NULL)
	{
		count++;
		s = s->next;
	}
	return count;
}

/* Function for swapping kth nodes from both ends of linked list */
void swapKth(struct Node **head, int k)
{
int n=countNodes(*head);
Node *prevx=NULL,*prevy=NULL,*x=*head,*y=*head;
for(int i=1;i<k;i++)
{prevx=x;
x=x->next;
}
for(int i=1;i<=n-k;i++)
{
    prevy=y;
    y=y->next;
}
if(prevx)
    prevx->next=y;
if(prevy)
    prevy->next=x;
Node *temp=x->next;
x->next=y->next;
y->next=temp;
if(k==1)
    *head=y;
if(k==n)
    *head=x;
}


// Driver program to test above functions
int main()
{
	// Let us create the following linked list for testing
	// 1->2->3->4->5->6->7->8
	struct Node *head = NULL;
	for (int i = 8; i >= 1; i--)
	push(&head, i);

	cout << "Original Linked List: ";
	printList(head);

	for (int k = 1; k < 9; k++)
	{
		swapKth(&head, k);
		cout << "\nModified List for k = " << k << endl;
		printList(head);
	}

	return 0;
}
