
#include<stdio.h> 
  
/* A tree node structure */
struct node 
{ 
  int data; 
  struct node *left; 
  struct node *right; 
}; 
  
// Convert a given tree to a tree where every node contains sum of values of 
// nodes in left and right subtrees in the original tree 
int toSumTree(struct node *node) 
{ 
    if(node==NULL)
    return 0;
    int left=toSumTree(node->left);
    int right=toSumTree(node->right);
    int num=node->data;
    node->data=left+node->data;
    return node->data+right;
} 
  
// A utility function to print inorder traversal of a Binary Tree 
void printInorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printInorder(node->left); 
     printf("%d ", node->data); 
     printInorder(node->right); 
} 
  
/* Utility function to create a new Binary Tree node */
struct node* newNode(int data) 
{ 
  struct node *temp = new struct node; 
  temp->data = data; 
  temp->left = NULL; 
  temp->right = NULL; 
  
  return temp; 
} 
  
/* Driver function to test above functions */
int main() 
{ 
  struct node *root = NULL; 
  int x; 
  
  /* Constructing tree given in the above figure */
  root = newNode(10); 
  root->left = newNode(-2); 
  root->right = newNode(6); 
  root->left->left = newNode(8); 
  root->left->right = newNode(-4); 
  root->right->left = newNode(7); 
  root->right->right = newNode(5); 
  
  toSumTree(root); 
  
  // Print inorder traversal of the converted tree to test result of toSumTree() 
  printf("Inorder Traversal of the resultant tree is: \n"); 
  printInorder(root); 
  

  return 0; 
}
