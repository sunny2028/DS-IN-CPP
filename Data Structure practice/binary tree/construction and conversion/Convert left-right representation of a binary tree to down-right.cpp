
/* C++ program to convert left-right to down-right 
   representation of binary tree */
#include <iostream> 
#include <queue> 
using namespace std; 
  
// A Binary Tree Node 
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
  
// An Iterative level order traversal based function to 
// convert left-right to down-right representation. 
void convert(node *root) 
{ 
    if(root==NULL)
    return;
    convert(root->left);
    convert(root->right);
    if(root->right)
    {
    	if(root->left)
    	{
		root->left->right=root->right;
    	root->right=NULL;
        }
        else
        {
        	root->left=root->right;
        	root->right=NULL;
		}
	}
	
	} 
  
// A utility function to traverse a tree stored in 
// down-right form. 
void downRightTraversal(node *root) 
{ 
    if (root != NULL) 
    { 
        cout << root->key << " "; 
        downRightTraversal(root->right); 
        downRightTraversal(root->left); 
    } 
} 
  
// Utility function to create a new tree node 
node* newNode(int key) 
{ 
    node *temp = new node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create binary tree shown in above diagram 
    /* 
           1 
         /   \ 
        2     3 
             / \ 
            4   5 
           /   /  \ 
          6   7    8 
    */
    node *root = newNode(1); 
    root->left = newNode(2); 
    root->left->right=newNode(9);
    root->right = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    root->right->left->left = newNode(6); 
    root->right->right->left = newNode(7); 
    root->right->right->right = newNode(8); 
  
    convert(root); 
  
    cout << "Traversal of the tree converted to down-right form\n"; 
    downRightTraversal(root); 
  
    return 0; 
}
