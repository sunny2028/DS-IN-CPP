// An iterative C program to check if two linked lists are
// identical or not
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Structure for a linked list node */
struct Node
{
	int data;
	struct Node *next;
};

/* Returns true if linked lists a and b are identical,
otherwise false */
bool areIdentical(struct Node *a, struct Node *b)
{
	if(a==NULL&&b==NULL)
	return true;
	else if(a!=NULL&&b!=NULL)
	{
	    if(a->data==b->data)
	    return areIdentical(a->next,b->next);
	    else
	    return false;
	}
	else
	return false;
}
/*bool areIdentical(struct Node *a, struct Node *b)
{
	if(a==NULL&&b==NULL)
	return true;
if(a!=NULL&&b!=NULL)
{
	return(a->data&&b->data)&&(a->next,b->next);
}
return false;
}*/

/* UTILITY FUNCTIONS TO TEST fun1() and fun2() */
/* Given a reference (pointer to pointer) to the head
of a list and an int, push a new node on the front
of the list. */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Druver program to test above function */
int main()
{
	/* The constructed linked lists are :
	a: 3->2->1
	b: 3->2->1 */
	struct Node *a = NULL;
	struct Node *b = NULL;
	push(&a, 1);
	push(&a, 2);
	push(&a, 3);
	push(&b, 1);
	push(&b, 2);
	push(&b, 3);

	areIdentical(a, b)? printf("Identical"):
						printf("Not identical");

	return 0;
}

