#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
  
/* A binary tree node has data, left child and right child */
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
/* A utility function to get the sum of values in tree with root 
  as root */

  int sum(node *root)
  {
  	if(root==NULL)
  	return 0;
  	int ls=sum(root->left);
  	int rs=sum(root->right);
  	return root->data+ls+rs;
  }
/* returns 1 if sum property holds for the given 
    node and both of its children */
int isSumTree(struct node* root) 
{ 
if(root==NULL||root->left==NULL&&root->right==NULL)
return 1;
int ls=sum(root->left);
int rs=sum(root->right);
if(root->data==ls+rs)
return isSumTree(root->left)&&isSumTree(root->right);
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
    struct node *root  = newNode(26); 
    root->left         = newNode(10); 
    root->right        = newNode(3); 
    root->left->left   = newNode(4); 
    root->left->right  = newNode(6); 
    root->right->right = newNode(3); 
    if(isSumTree(root)) 
        printf("The given tree is a SumTree "); 
    else
        printf("The given tree is not a SumTree "); 
  

    return 0; 
}
