#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// Temporary node for case 2
Node* temp = new Node;
 
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int leftmost(Node *x)
{
	Node *pre=x->right;
	while(pre->left)
	{
		pre=pre->left;
	}
	return pre->data;
	
}
Node *rightmost(Node *root)
{
	while(root->right)
	{
		root=root->right;
	}
	return root;
}
Node *inorder(Node *root,Node *x)
{
	if(!root)
	return NULL;
	  if(root==x)
	     return root;
	     Node *s=inorder(root->left,x);
	     if(s)
	     {
	     	if(root->left==s)
	    {
	    	cout<<root->data<<" ";
	    	return NULL;
		}
		else
		return root;
		 }
		 else
		 {
		 	Node *t=inorder(root->right,x);
		 	if(t)
		 	{
		 	 	if(root->left==t)
	    {
	    	cout<<root->data<<" ";
	    	return NULL;
		}
		else
		return root;
			}
			else
			return NULL;
		 }
	     
}
void inorderSuccesor(Node *root,Node *x)
{
	if(x->right)
	{
		cout<<leftmost(x)<<" ";
	}
	else
	{
		Node *t=rightmost(root);
		if(t==x)
		{
		cout<<-1;
		return;
	    }
	    else
	    {
	     Node *in=inorder(root,x);
		}
	}
}
int main()
{
    // Let's construct the binary tree 
    // as shown in above diagram
 
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    // Case 1 
    inorderSuccesor(root, root->right);
 
    // case 2
    inorderSuccesor(root, root->left->right);
 
    // case 3
    inorderSuccesor(root, root->right->right);
 
    return 0;
}

