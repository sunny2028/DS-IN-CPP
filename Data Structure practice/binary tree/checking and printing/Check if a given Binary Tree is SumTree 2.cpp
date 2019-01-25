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
  int isleaf(node *root)
  {
  	return(root->left==NULL&&root->right==NULL);
  }
//  int sum(node *root)
//  {
//  	if(root==NULL)
//  	return 0;
//  	if(isleaf(root))
//  	return root->data;
//  	int n=sum(root->left);
//  	int n1=sum(root->right);
//  	if(n+n1==root->data)
//  	return 2*root->data;
//  	return INT_MIN;
//  }
//int isSumTree(struct node* root) 
//{ 
//if(isleaf(root))
//return 1;
//int n=sum(root);
//if(n==2*root->data)
//return 1;
//return 0;
//}
int isSumTree(node *root)
{
	if(root==NULL||isleaf(root))
	return 1;
	int ls=0;
	int rs=0;
	
	if(isSumTree(root->left)&&isSumTree(root->right))
	{    
		if(root->left==NULL)
		ls=0;
		else if(isleaf(root->left))
		ls=root->left->data;
		else
		ls=2*root->left->data;
		
		if(root->right==NULL)
		rs=0;
		else if(isleaf(root->right))
		rs=root->right->data;
		else
		rs=2*root->right->data;
		return root->data==rs+ls;
	}
	return 0;
	
}

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
