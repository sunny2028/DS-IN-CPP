#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 
#include <stack> 
  
using namespace std; 
  
/* A binary tree node has data, left child and right child */
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
/* Helper function that allocates a new node with the given data and 
   NULL left and right  pointers.*/
struct node* newNode(int data) 
{ 
    struct node* node = new struct node; 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
} 
  
// An iterative process to print preorder traversal of Binary tree 
void iterativePreorder(node *root) 
{ 
  stack<node *>s;
  s.push(root);
  while(!s.empty())
  {
  	node *temp=s.top();
  	s.pop();
  	cout<<temp->data<<" ";
  	if(temp->right)
  	s.push(temp->right);
  	if(temp->left)
  	s.push(temp->left);
  }
   
} 
  
// Driver program to test above functions 
int main() 
{ 
    /* Constructed binary tree is 
            10 
          /   \ 
        8      2 
      /  \    / 
    3     5  2 
  */
  struct node *root = newNode(10); 
  root->left        = newNode(8); 
  root->right       = newNode(2); 
  root->left->left  = newNode(3); 
  root->left->right = newNode(5); 
  root->right->left = newNode(2); 
  iterativePreorder(root); 
  return 0; 
} 
