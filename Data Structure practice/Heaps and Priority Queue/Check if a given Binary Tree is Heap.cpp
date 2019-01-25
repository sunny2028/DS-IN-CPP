#include<bits/stdc++.h>
struct Node 
{ 
    int data; 
    struct Node *left; 
    struct Node *right; 
}; 
  
/* Helper function that allocates a new node */
struct Node *newNode(int k) 
{ 
    struct Node *node = (struct Node*)malloc(sizeof(struct Node)); 
    node->data = k; 
    node->right = node->left = NULL; 
    return node; 
} 
int countNodes(Node* root)
{
	if(root==NULL)
	return 0;
	return 1+countNodes(root->left)+countNodes(root->right);
}
bool isHeapUtil(Node* root,int index,int n)
{    
	if(root==NULL)
	return true;
	if(index>=n)
          return false;
          return isHeapUtil(root->left,2*index+1,n)&&isHeapUtil(root->right,2*index+2,n);	
}
bool check(Node* root)
{
	if(root->left==NULL&&root->right==NULL)
	  return true;
	  if(root->right==NULL)
	  {
	  	return(root->data > root->left->data);
	  }
	  else
	  return root->data>root->left->data&&root->data>root->right->data&&check(root->left)&&check(root->right);
	
}
bool isHeap(Node* root)
{
	int n=countNodes(root);
	return isHeapUtil(root,0,n)&&check(root);
}
 int main() 
{ 
    struct Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(9); 
    root->right = newNode(8); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    root->left->left->left = newNode(3); 
    root->left->left->right = newNode(2); 
    root->left->right->left = newNode(1); 
  
    if (isHeap(root)) 
        printf("Given binary tree is a Heap\n"); 
    else
        printf("Given binary tree is not a Heap\n"); 
  
    return 0; 
} 
