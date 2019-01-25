#include <bits/stdc++.h> 
using namespace std; 
  
// Tree node structure used in the program 
struct Node { 
    int data; 
    Node *left, *right; 
}; 
  
struct Node* newNode(int data) 
{ 
    struct Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
  
    return (node); 
}
int dia(Node *root,int &maxi,Node*(&k),int &lh,int &rh)
{
	if(root==NULL)
	return 0;
  int l=dia(root->left,maxi,k,lh,rh);
  int r=dia(root->right,maxi,k,lh,rh);
  int n=1+l+r;
  if(n>maxi)
  {
  maxi=n;
  k=root;
  lh=l;
  rh=r;
   }
  return 1+max(l,r);
}
void printside(int *arr,int n,int f)
{
	if(f==0)
	{
		for(int i=n-1;i>=0;i--)
		cout<<arr[i]<<" ";
	}
	else
	{
		for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	}
}
void print(Node *root,int *arr,int max,int index,int &f)
{
	if(root==NULL)
	return;
	arr[index]=root->data;
	index++;
	if(root->left==NULL&&root->right==NULL)
	{
		if(index==max&&(f==0||f==1))
		   {
		   	printside(arr,max,f);
		   	f=2;
		   }
		   return;
	}
	print(root->left,arr,max,index,f);
	print(root->right,arr,max,index,f);
	
}
void diameter(Node *root)
{
	if(root==NULL)
	return ;
	int max=INT_MIN;
	Node *k;
	int lh=0,rh=0;
	int d=dia(root,max,k,lh,rh);
	int larr[100],index=0;
	int f=0;
	print(k->left,larr,lh,index,f);
	cout<<k->data<<" ";
	int rarr[100];
    f=1;
    print(k->right,rarr,rh,index,f);
}
int main() 
{ 
    // Enter the binary tree ... 
    //           1 
    //         /   \      
    //        2     3 
    //      /   \    
    //     4     5 
    //      \   / \  
    //       8 6   7 
    //      / 
    //     9 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->left = newNode(6); 
    root->left->right->right = newNode(7); 
    root->left->left->right = newNode(8); 
    root->left->left->right->left = newNode(9); 
  
    diameter(root); 
  
    return 0; 
} 
