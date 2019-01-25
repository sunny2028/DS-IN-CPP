
#include<iostream>
  
#include <stdio.h> 
#include <stdlib.h> 
  
struct node 
{ 
  int data; 
  struct node* left; 
  struct node* right; 
}; 
  void printInorder(struct node* node) 
{ 
  if (node == NULL) 
    return; 
  
  /* first recur on left child */
  printInorder(node->left); 
  
  /* then print the data of node */
  printf("%d ", node->data); 
  
  /* now recur on right child */
  printInorder(node->right); 
} 
  
/* Helper function that allocates a new node 
 with the given data and NULL left and right 
 pointers. */
struct node* newNode(int data) 
{ 
  struct node* node = 
      (struct node*)malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  return(node); 
} 
  void check(node * root,int diff)
{
	if(root->left)
	{
		root->left->data+=diff;
		check(root->left,diff);
	}
	else if(root->right)
	{
		root->right->data+=diff;
		check(root->right,diff);
	}
}
void convertTree(node *root)
{
	int left=0,right=0;
	if(root==NULL||root->left==NULL&&root->right==NULL)
	return;
	convertTree(root->left);
	convertTree(root->right);
	   if(root->left)
      left=root->left->data;
      if(root->right)
      right=root->right->data;
      int diff=left+right-root->data;
      if(diff>0)
      root->data=root->data+diff;
      if(diff<0)
       check(root,-diff);
}

int main() 
{ 
  struct node *root = newNode(50); 
  root->left        = newNode(7); 
  root->right       = newNode(2); 
  root->left->left  = newNode(3); 
  root->left->right = newNode(5); 
  root->right->left  = newNode(1); 
  root->right->right = newNode(30); 
  
  printf("\n Inorder traversal before conversion "); 
  printInorder(root); 
  
  convertTree(root); 
  
  printf("\n Inorder traversal after conversion "); 
  printInorder(root); 
   
  return 0; 
}
