#include <bits/stdc++.h> 
using namespace std; 
  
// structure of a node of binary tree 
struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct Node* getNode(int data) 
{ 
    struct Node *newNode = new Node; 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
void print(Node *root,int x,int *arr,int i,int &f)
{
	if(root==NULL)
	return;
	if(root->data==x)
	{
		arr[i++]=x;
		f=1;
		return;
		
	}
	arr[i]=root->data;
	print(root->left,x,arr,i+1,f);
	if(f==0)
	print(root->right,x,arr,i+1,f);
}
void printPath(Node *root,int x)
{
int arr[100]={0};
int index=0;
int f=0;
print(root,x,arr,index,f);
int i=0;
while(arr[i]!=x)
{
	cout<<arr[i]<<" ";
	i++;
}
cout<<arr[i];

}
int main() 
{ 
    // binary tree formation 
    struct Node *root = getNode(1); 
    root->left = getNode(2); 
    root->right = getNode(3); 
    root->left->left = getNode(4); 
    root->left->right = getNode(5); 
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 
          
    int x = 6; 
    printPath(root, x); 
    return 0; 
}
