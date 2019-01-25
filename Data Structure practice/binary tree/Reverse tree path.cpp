#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *left, *right;
};
 Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
Node *reverseutil(map<int,int>&m,Node *root,int level,int data,int &nextpos)
{
	if(root==NULL)
	return NULL;
	if(root->data==data)
	{
		m[level]=root->data;
		root->data=m[nextpos];
		nextpos++;
		return root;
	}
	m[level]=root->data;
	Node *right;
	Node *left=reverseutil(m,root->left,level+1,data,nextpos);
	if(left==NULL)
	right=reverseutil(m,root->right,level+1,data,nextpos);
	if(left||right)
	{
	   root->data=m[nextpos];
	   nextpos++;
	   return (left?left:right);
	}
	return NULL;
}
 void reverseTreePath(Node *root,int data)
 {
 	map<int,int>m;
 	int nextpos=0;
 	reverseutil(m,root,0,data,nextpos);
 }
// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node* root = newNode(7);
    root->left = newNode(6);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(3);
    root->right->left = newNode(2);
    root->right->right = newNode(1);
 
    /*     7
         /    \
        6       5
       / \     / \
      4  3     2  1          */
 
    int data = 4;
 
    // Reverse Tree Path
    reverseTreePath(root, data);
 
    // Traverse inorder
    inorder(root);
    return 0;
}
