// C++ program to find largest BST in a 
// Binary Tree. 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, 
pointer to left child and a 
pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

/* Helper function that allocates a new 
node with the given data and NULL left 
and right pointers. */
struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 

	return(node); 
} 

//// Information to be returned by every 
//// node in bottom up traversal. 
//struct Info 
//{ 
//	int sz; // Size of subtree 
//	int max; // Min value in subtree 
//	int min; // Max value in subtree 
//	int ans; // Size of largest BST which 
//	// is subtree of current node 
//	bool isBST; // If subtree is BST 
//}; 

// Returns Information about subtree. The 
// Information also includes size of largest 
// subtree which is a BST. 
void largestutil(Node* root,int min,int max,int &count,int &maxi)
{
    if(root==NULL)
    return ;
    if(root->data>min&&root->data<max)
    {
        count++;
        largestutil(root->left,min,root->data,count,maxi);
            largestutil(root->right,root->data,max,count,maxi);
            if(count>maxi)
            maxi=count;
        return;
    }
    count=0;
        largestutil(root->left,INT_MIN,INT_MAX,count,maxi);
}
int largestBst(Node *root)
{
int min=INT_MIN;
int max=INT_MAX;
int count=0;
int maxi=0;
largestutil(root,min,max,count,maxi);
return maxi;
}
/* Driver program to test above functions*/
int main() 
{ 
	/* Let us construct the following Tree 
		60 
	/ \ 
	65 70 
	/ 
	50 */

	struct Node *root = newNode(60); 
	root->left = newNode(65); 
	root->right = newNode(70); 
	root->left->left = newNode(50); 
	printf(" Size of the largest BST is %d\n", 
		largestBst(root)); 
	return 0; 
} 

// This code is contributed by Vivek Garg in a 
// comment on below set 1. 
// www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/ 

