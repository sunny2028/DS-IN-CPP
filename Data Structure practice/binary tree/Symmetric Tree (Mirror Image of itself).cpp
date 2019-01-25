#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left=NULL;
	Node *right=NULL;
};
	Node* newNode(int dta)
	{Node *newnode=new Node;
	newnode->data=dta;
	return newnode;	
	}
bool ischeck(Node *root,Node *root1)
{
	if(root==NULL&&root1==NULL)
	return true;
	else if(root&&root1&&(root->data==root1->data))
	return ischeck(root->left,root1->right);
	else
	return false;
}
bool isSymmetric(Node *root)
{
	return ischeck(root,root);
}

int main()
{
	  Node *root  = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left  = newNode(4);
    root->right->right = newNode(3);
 
    cout << isSymmetric(root);
    return 0;
}
