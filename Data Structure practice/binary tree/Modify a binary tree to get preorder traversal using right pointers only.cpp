
// C code to modify binary tree for 
// traversal using only right pointer 
#include <iostream> 
#include <stack> 
#include <stdio.h> 
#include <stdlib.h> 
  
using namespace std; 
  
// A binary tree node has data, 
// left child and right child 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
  
// Helper function that allocates a new 
// node with the given data and NULL 
// left and right  pointers. 
struct Node* newNode(int data) 
{ 
    struct Node* node = new struct Node; 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return (node); 
} 
  
// An iterative process to set the right 
// pointer of Binary tree 
void modifytree(struct Node* root) 
{
stack<Node *>s;
Node *pre=NULL;
s.push(root);
while(!s.empty())
{
Node *temp=s.top();
s.pop();
if(temp->right)
s.push(temp->right);
if(temp->left)
s.push(temp->left);
if(pre)
{
	pre->right=temp;
}
pre=temp;
}
}
  
// printing using right pointer only 
void printpre(struct Node* root) 
{ 
    while (root != NULL) { 
        cout << root->data << " "; 
        root = root->right; 
    } 
} 
  
// Driver code 
int main() 
{ 
    /* Constructed binary tree is 
            10 
          /   \ 
        8      2 
      /  \     
    3     5   
  */
    struct Node* root = newNode(10); 
    root->left = newNode(8); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    root->left->right = newNode(5); 
  
    modifytree(root); 
    printpre(root); 
  
    return 0; 
} 
