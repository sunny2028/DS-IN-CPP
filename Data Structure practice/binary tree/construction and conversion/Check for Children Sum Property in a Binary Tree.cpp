#include <stdio.h> 
#include <stdlib.h> 
  
/* A binary tree node has data, left child and right child */
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
/* returns 1 if children sum property holds for the given 
    node and both of its children*/
int isSumProperty(struct node* root) 
{ 
  if(root==NULL||root->left==NULL&&root->right==NULL)
  return 1;
  int left=0,right=0;
  if(root->left)
  left=root->left->data;
  if(root->right)
  right=root->right->data;
  if(root->data==left+right)
  return( isSumProperty(root->left)&&isSumProperty(root->right));
  else
  return 0;
} 
  
/* 
 Helper function that allocates a new node 
 with the given data and NULL left and right 
 pointers. 
*/
struct node* newNode(int data) 
{ 
  struct node* node = 
      (struct node*)malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  return(node); 
} 
  
/* Driver program to test above function */
int main() 
{ 
  struct node *root  = newNode(10); 
  root->left         = newNode(8); 
  root->right        = newNode(2); 
  root->left->left   = newNode(3); 
  root->left->right  = newNode(5); 
  root->right->right = newNode(2); 
  if(isSumProperty(root)) 
    printf("The given tree satisfies the children sum property "); 
  else
    printf("The given tree does not satisfy the children sum property "); 
  
 // getchar(); 
  return 0; 
} 
