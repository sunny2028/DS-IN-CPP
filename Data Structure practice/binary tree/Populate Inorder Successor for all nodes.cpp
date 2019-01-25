#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left=NULL;
	Node *right=NULL;
	Node *next=NULL;
};
Node *newnode(int d)
{
	Node *nn=new Node;
	nn->data=d;
	return nn;
}
void populateNext(Node * root)
{
	static Node *n=NULL;
	if(root== NULL)
	return;
	populateNext(root->left);
	root->next=n;
	n=root;
	populateNext(root->right);
}
int main()
{
 
    /* Constructed binary tree is
              10
            /   \
          8      12
        /
      3
    */
    struct Node *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(12);
    root->left->left  = newnode(3);
 
    // Populates nextRight pointer in all nodes
    populateNext(root);
 
    // Let us see the populated values
    struct Node *ptr = root->right;
    while(ptr)
    {
        // -1 is printed if there is no successor
        printf("Next of %d is %d \n", ptr->data, ptr->next? ptr->next->data: -1);
        ptr = ptr->next;
    }
 
    return 0;
}

