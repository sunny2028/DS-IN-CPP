// C++ program to remove all 
// occurrences of duplicates 
// from a sorted linked list.
#include <bits/stdc++.h>
using namespace std;

// A linked list node
struct Node
{
	int data;
	struct Node *next;
};

// Utility function 
// to create a new Node
struct Node *newNode(int data)
{
Node *temp = new Node;
temp -> data = data;
temp -> next = NULL;
return temp;
}

// Function to print nodes 
// in a given linked list.
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node -> data);
		node = node -> next;
	}
}

// Function to remove all occurrences
// of duplicate elements
void removeAllDuplicates(struct Node **start)
{
Node *temp=*start;
Node *prev=NULL;
*start=NULL;
while(temp)
{
    if(temp->data==temp->next->data)
    {
        int d=temp->data;
        while(temp&&temp->data==d)
        {
            temp=temp->next;
        }
        if(prev!=NULL)
        prev->next=temp;
    }
    else
    {
        if(!prev)
        *start=temp;
        prev=temp;
        temp=temp->next;
    }
}

}

// Driver Code
int main() 
{
	// 23->28->28->35->49->49->53->53
	struct Node* start = newNode(23);
	start -> next = newNode(28);
	start -> next -> next = newNode(28);
	start -> next -> 
	next -> next = newNode(35);
	start -> next -> 
	next -> next -> next = newNode(49);
	start -> next -> 
	next -> next -> 
	next -> next = newNode(49);
	start -> next -> 
	next -> next -> 
	next -> next -> next = newNode(53);
	start -> next -> 
	next -> next -> 
	next -> next -> 
	next -> next = newNode(53);
	cout << "List before removal " <<
				"of duplicates\n";
	printList(start);
	
	removeAllDuplicates(&start);
	
	cout << "\nList after removal " << 
				"of duplicates\n";
	printList(start);
	return 0;
}

// This code is contributed 
// by NIKHIL JINDAL

