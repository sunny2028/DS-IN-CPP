
// C++ program to find sum of Covered and Uncovered node of 
// binary tree 
#include <bits/stdc++.h> 
using namespace std; 
  
/* A binary tree node has key, pointer to left 
   child and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
  
/* To create a newNode of tree and return pointer */
struct Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 
int totalsum(Node *root)
{
	if(root==NULL)
	return 0;
	return root->data+totalsum(root->left)+totalsum(root->right);
}
void leftsum(Node *root,int &sum)
{    if(root==NULL)
       return ;
       sum=sum+root->data;
	if(root->left)
	{
		
		leftsum(root->left,sum);
	}
	else if(root->right)
	{
	
		leftsum(root->right,sum);
	}
	
}
void rightsum(Node *root,int &sum)
{
	if(root==NULL)
	return ;
	sum=sum+root->data;
	if(root->right)
	{
		rightsum(root->right,sum);
	}
	else if(root->left)
	{
		rightsum(root->left,sum);
	}
}
int isSumSame(Node *root)
{	
	int n=totalsum(root);
	int sum=0;
	leftsum(root->left,sum);
	int sum1=0;
	rightsum(root->right,sum1);
//	cout<<n<<'\n'<<sum<<'\n'<<sum1<<"\n";
	if(n==(root->data+sum+sum1)*2)
	return 1;
	else
	return 0;
		
}
void inorder(Node* root) 
{ 
    if (root) 
    { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Making above given diagram's binary tree 
    Node* root = newNode(8); 
    root->left = newNode(3); 
  
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(39); 
  
    root->right = newNode(10); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
  
    if (isSumSame(root)) 
        printf("Sum of covered and uncovered is same\n"); 
    else
        printf("Sum of covered and uncovered is not same\n"); 
}
