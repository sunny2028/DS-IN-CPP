#include<bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
  
// utility function to create a new node 
struct Node* newNode(int x) 
{ 
    struct Node* temp = new Node; 
    temp->data = x; 
    temp->left = temp->right = NULL; 
    return temp; 
}; 
  
int a=0;
int findsize(Node *root)
{
	if(!root)
	return 0;
	int left=findsize(root->left);
	int right=findsize(root->right);
	return 1+left+right;
}
int cann(Node *root,int size)
{
	if(root==NULL)
	return 0;
	int left=cann(root->left,size);
	int right=cann(root->right,size);
	if(abs(left-right)==1&&left+right+1==size)
	{
	a=1;
	}
		return left+right+1;
}
int can(Node *root)
{
	int size=findsize(root);
	if(size%2==1)
	return a;
	cann(root,size);
	return a;
}
int main() 
{ 
    struct Node* root = newNode(5); 
    root->left = newNode(1); 
    root->right = newNode(6); 
    root->left->left = newNode(3); 
    root->right->left = newNode(7); 
    root->right->right = newNode(4); 
  
    can(root)?  printf("YES") : printf("NO"); 
  
    return 0; 
} 
