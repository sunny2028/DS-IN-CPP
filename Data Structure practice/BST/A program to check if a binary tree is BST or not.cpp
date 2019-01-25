#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>
using namespace std; 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
//int isBSTUtil(struct node* node, int min, int max); 
//  
///* Returns true if the given tree is a binary search tree  
// (efficient version). */ 
//int isBST(struct node* node)  
//{  
//  return(isBSTUtil(node, INT_MIN, INT_MAX));  
//}  
  int isBST(node* root,node* l=NULL,node*r =NULL)
  {
  	if(root==NULL)
  	return true;
  	if(l!=NULL&&root->data<l->data)
  	return 0;
  	if(r!=NULL&&root->data>r->data)
  	return 0;
  	return isBST(root->left,l,root)&&isBST(root->right,root,r);
  }
  
/* Returns true if the given tree is a BST and its  
   values are >= min and <= max. */ 
//int isBSTUtil(struct node* root, int min, int max)  
//{  
// if(root==NULL)
// return 1;
// if(root->data<min||root->data>max)
// return 0;
// return isBSTUtil(root->left,min,root->data)&&isBSTUtil(root->right,root->data,max); 
//}  
//  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
  struct node *root = newNode(4); 
  root->left        = newNode(2); 
  root->right       = newNode(5); 
  root->left->left  = newNode(1); 
  root->left->right = newNode(3);  
  
  if(isBST(root)) 
    printf("Is BST"); 
  else
    printf("Not a BST"); 
       
  return 0; 
}
