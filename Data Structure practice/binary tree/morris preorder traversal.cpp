#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
  using namespace std;
struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
    struct node* temp = (struct node*) malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Preorder traversal without recursion and without stack 
void morrisTraversalPreorder(struct node* root) 
{ 
   while(root)
   {
   	if(root->left==NULL)
   	{
   	  cout<<root->data<<" ";
      root=root->right;	
    }
    else
    {
    	node *pre=root->left;
    	while(pre->right&&pre->right!=root)
    	pre=pre->right;
    	if(!pre->right)
    	{
    		cout<<root->data<<" ";
    		pre->right=root;
    		root=root->left;
		}
		else if(pre->right==root)
		{
			pre->right=NULL;
			root=root->right;
		}
	}
   }
} 
  
// Function for sStandard preorder traversal 
void preorder(struct node* root) 
{ 
    if (root) 
    { 
        printf( "%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    struct node* root = NULL; 
  
    root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
  
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left = newNode(8); 
    root->left->left->right = newNode(9); 
  
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(11); 
  
    morrisTraversalPreorder(root); 
  
    printf("\n"); 
    preorder(root); 
  
    return 0; 
}
