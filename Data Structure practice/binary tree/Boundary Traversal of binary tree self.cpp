#include<bits/stdc++.h>
#include <stdio.h> 
#include <stdlib.h> 
  using namespace std;
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 
void printleft(node *root)
{
	if(root)
	{
		if(root->left)
		{
			cout<<root->data<<" ";
			printleft(root->left);
		}
		else if(root->right)
		{
			cout<<root->data<<" ";
			printleft(root->right);
		}
	}
}
void printright(node *root)
{
	if(root)
	{
		if(root->right)
		{
			printright(root->right);
			cout<<root->data<<" ";
		}
		else if(root->left)
		{
			printright(root->left);
			cout<<root->data<<" ";
			
		}
	}
}
void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		inorder(root->right);
		if(root->left==NULL&&root->right==NULL)
		  cout<<root->data<<" ";
		  
	}
}
void printBoundary (struct node* root) 
{ 
 if(root==NULL)
 return ;
 cout<<root->data<<" ";
 printleft(root->left);
 inorder(root->left);
 inorder(root->right);
 printright(root->right);
 
} 
  
// A utility function to create a node 
struct node* newNode( int data ) 
{ 
    struct node* temp = (struct node *) malloc( sizeof(struct node) ); 
  
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us construct the tree given in the above diagram 
    struct node *root         = newNode(20); 
    root->left                = newNode(8); 
    root->left->left          = newNode(4); 
    root->left->right         = newNode(12); 
    root->left->right->left   = newNode(10); 
    root->left->right->right  = newNode(14); 
    root->right               = newNode(22); 
    root->right->right        = newNode(25); 
  
    printBoundary( root ); 
  
    return 0; 
} 
