#include<iostream> 
using namespace std; 
  
// A BST node 
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
// A utility function to create a new Binary Tree Node 
struct Node *newNode(int item) 
{ 
    struct Node *temp =  new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
void transformTreeUtil(Node* root,int &sum)
{
	if(root==NULL)
	{
		return;
	}
	transformTreeUtil(root->right,sum);
sum=sum+root->data;
root->data=sum-root->data;
	transformTreeUtil(root->left,sum);
}
void transformTree(struct Node *root) 
{ 
    int sum = 0; // Initialize sum 
    transformTreeUtil(root, sum); 
} 
void printInorder(struct Node *root) 
{ 
    if (root == NULL) return; 
  
    printInorder(root->left); 
    cout << root->data << " "; 
    printInorder(root->right); 
} 
  
// Driver Program to test above functions 
int main() 
{ 
    struct Node *root = newNode(11); 
    root->left = newNode(2); 
    root->right = newNode(29); 
    root->left->left = newNode(1); 
    root->left->right = newNode(7); 
    root->right->left = newNode(15); 
    root->right->right = newNode(40); 
    root->right->right->left = newNode(35); 
  
    cout << "Inorder Traversal of given tree\n"; 
    printInorder(root); 
  
    transformTree(root); 
  
    cout << "\n\nInorder Traversal of transformed tree\n"; 
    printInorder(root); 
  
    return 0; 
} 
