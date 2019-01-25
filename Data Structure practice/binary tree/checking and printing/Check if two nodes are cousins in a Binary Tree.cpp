#include <stdio.h> 
#include <stdlib.h> 
  
// A Binary Tree Node 
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
// A utility function to create a new Binary Tree Node 
struct Node *newNode(int item) 
{ 
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
  int issibling(Node *root,Node *a,Node *b)
  {
  	if(root==NULL)
  	return 0;
  	return(root->left==a&&root->right==b||root->left==b&&root->right==a||issibling(root->left,a,b)||issibling(root->right,a,b));
  }
int level(Node *root,Node *a,int l)
{
	if(root==NULL)
	return 0;
	if(root==a)
	return l;
	int k=level(root->left,a,l+1);
	if(k)
	return k;
	return level(root->right,a,l+1);
}
// Returns 1 if a and b are cousins, otherwise 0 
int isCousin(struct Node *root, struct Node *a, struct Node *b) 
{ 
if(level(root,a,1)==level(root,b,1)&&(!issibling(root,a,b)))
return 1;
return 0;
} 
  
// Driver Program to test above functions 
int main() 
{ 
    struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(15); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    struct Node *Node1,*Node2; 
    Node1 = root->left->left; 
    Node2 = root->right->right; 
  
    isCousin(root,Node1,Node2)? puts("Yes"): puts("No"); 
  
    return 0; 
}
