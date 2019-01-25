#include<bits/stdc++.h> 
using namespace std; 
  
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
  
/* utility that allocates a new node with the 
given data and NULL left and right pointers. */
struct Node* newnode(int data) 
{ 
    struct Node* node = new Node; 
    node->data = data; 
    node->left = node->right  = NULL; 
    return (node); 
} 
  
// function to check given sequence of root to leaf path exist 
// in tree or not. 
// index represents current element in sequence of rooth to 
// leaf path 
bool check(Node *root,int *arr,int n,int k)
{
	if(root==NULL)
	{
		if(k==n)
		return true;
		return false;
	}
	if(k<n)
	{
	if(root->data!=arr[k])
	return false;
	return check(root->left,arr,n,k+1)||check(root->right,arr,n,k+1);
    }
    return false;
}




  
// Driver function to run the case 
int main() 
{ 
    // arr[] --> sequence of root to leaf path 
    int arr[] = {5, 8, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    struct Node *root = newnode(5); 
    root->left    = newnode(3); 
    root->right   = newnode(8); 
    root->left->left = newnode(2); 
    root->left->right = newnode(4); 
    root->left->left->left = newnode(1); 
    root->right->left = newnode(6); 
    root->right->left->right = newnode(7); 
  
    check(root, arr, n, 0)? cout << "Path Exists" : 
                                cout << "Path does not Exist"; 
    return 0; 
}
