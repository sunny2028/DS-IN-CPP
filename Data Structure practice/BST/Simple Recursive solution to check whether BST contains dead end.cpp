#include <bits/stdc++.h> 
using namespace std; 

// A BST node 
struct Node { 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to create a new node 
Node* newNode(int data) 
{ 
	Node* temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

/* A utility function to insert a new Node 
with given key in BST */
struct Node* insert(struct Node* node, int key) 
{ 
	/* If the tree is empty, return a new Node */
	if (node == NULL) 
		return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->data) 
		node->left = insert(node->left, key); 
	else if (key > node->data) 
		node->right = insert(node->right, key); 

	/* return the (unchanged) Node pointer */
	return node; 
} 

// Returns true if tree with given root contains 
// dead end or not. min and max indicate range 
// of allowed values for current node. Initially 
// these values are full range. 
bool deadEnd(Node* root, int min=1, int max=INT_MAX) 
{ 
if(root==NULL)
	return false;
	if(min==max)
	return true;
	return deadEnd(root->left,min,root->data-1)||deadEnd(root->right,root->data+1,max);
} 

// Driver program 
int main() 
{ 
	/* 8 
	/ \ 
	5 11 
	/ \ 
	2 7 
	\ 
	3 
	\ 
		4 */
	Node* root = NULL; 
	root = insert(root, 8); 
	root = insert(root, 5); 
	root = insert(root, 2); 
	root = insert(root, 3); 
	root = insert(root, 7); 
	root = insert(root, 11); 
	root = insert(root, 4); 
	if (deadEnd(root) == true) 
		cout << "Yes " << endl; 
	else
		cout << "No " << endl; 
	return 0; 
} 

