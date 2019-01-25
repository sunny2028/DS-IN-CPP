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
void iterativepostorder(node *root) 
{ 
stack<node *>s;
stack<node *>st;
s.push(root);
while(!s.empty())
{
	node *temp=s.top();
	s.pop();
	st.push(temp);
	if(temp->left)
	s.push(temp->left);
	if(temp->right)
	s.push(temp->right);
}
while(!st.empty())
{
	cout<<st.top()<<" ";
	st.pop();
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
  iterativepostorder(root); 
  return 0; 
} 
