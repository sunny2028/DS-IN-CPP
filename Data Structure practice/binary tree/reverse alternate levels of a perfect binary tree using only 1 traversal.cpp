#include <bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    char key; 
    Node *left, *right; 
}; 
  
void preorder(struct Node *root1, struct Node* root2) 
{ 
  if(root1==NULL||root2==NULL)
  return ;
  swap(root1->key,root2->key);
  preorder(root1->left,root2->right);
  preorder(root1->right,root2->left);   
} 
  
// This function calls preorder() for left and right children 
// of root 
void reverseAlternate(struct Node *root) 
{ 
   preorder(root->left, root->right); 
} 
  
// Inorder traversal (used to print initial and 
// modified trees) 
void printInorder(struct Node *root) 
{ 
    if (root == NULL) 
       return; 
    printInorder(root->left); 
    cout << root->key << " "; 
    printInorder(root->right); 
} 
  
// A utility function to create a new node 
Node *newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->left = temp->right = NULL; 
    temp->key = key; 
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    struct Node *root = newNode('a'); 
    root->left = newNode('b'); 
    root->right = newNode('c'); 
    root->left->left = newNode('d'); 
    root->left->right = newNode('e'); 
    root->right->left = newNode('f'); 
    root->right->right = newNode('g'); 
    root->left->left->left = newNode('h'); 
    root->left->left->right = newNode('i'); 
    root->left->right->left = newNode('j'); 
    root->left->right->right = newNode('k'); 
    root->right->left->left = newNode('l'); 
    root->right->left->right = newNode('m'); 
    root->right->right->left = newNode('n'); 
    root->right->right->right = newNode('o'); 
  
    cout << "Inorder Traversal of given tree\n"; 
    printInorder(root); 
  
    reverseAlternate(root); 
  
    cout << "\n\nInorder Traversal of modified tree\n"; 
    printInorder(root); 
    return 0; 
} 
