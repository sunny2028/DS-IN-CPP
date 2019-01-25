#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int key; 
	Node *left, *right; 
}; 

// To create new BST Node 
Node* newNode(int item) 
{ 
	Node* temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// To insert a new node in BST 
Node* insert(Node* node, int key) 
{ 
	// if tree is empty return new node 
	if (node == NULL) 
		return newNode(key); 

	// if key is less then or grater then 
	// node value then recur down the tree 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	// return the (unchanged) node pointer 
	return node; 
} 

// function to find max value less then N 
int findMaxforN(Node* root, int k) 
{ 
	if(root==NULL)
	return -1;
	if(root->key==k)
	return k;
	if(root->key<k)
	{     
		int j= findMaxforN(root->right,k);
		if(j==-1)
		return root->key;
		
		return j;
	}
	else
	{
		return findMaxforN(root->left,k);
	}
} 

// Driver code 
int main() 
{ 
	int N = 4; 

	// creating following BST 
	/* 
				5 
			/ \ 
			2	 12 
		/ \ / \ 
		1 3 9 21 
					/ \ 
					19 25 */
	Node* root = insert(root, 25); 
	insert(root, 2); 
	insert(root, 1); 
	insert(root, 3); 
	insert(root, 12); 
	insert(root, 9); 
	insert(root, 21); 
	insert(root, 19); 
	insert(root, 25); 

	printf("%d", findMaxforN(root, N)); 

	return 0; 
} 

