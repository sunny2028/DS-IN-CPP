#include <iostream> 
using namespace std; 
  
// A node of binary tree 
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
// A utility function to create a new Binary Tree node 
Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
void print(Node *root,int i,int h)
{
	if(root==NULL)
	return;
	if(i==h)
	cout<<root->data<<" ";
	print(root->left,i,h-1);
	print(root->right,i,h+1);
}
void find(Node *root,int &min,int &max,int h)
{
	if(root==NULL)
	     return;
	if(h<min)
	 min=h;
	 if(max<h)
	 max=h;
	 find(root->left,min,max,h-1);
	 find(root->right,min,max,h+1);
}
void printvertical(Node *root)
{
	int min=0;
	int max=0;
	int h=0;
	find(root,min,max,h);
	for(int i=min;i<=max;i++)
	{
		print(root,i,h);
		cout<<"\n";
	}
}
// Driver program to test above functions 
int main() 
{ 
    // Create binary tree shown in above figure 
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
  
    cout << "Vertical order traversal is \n"; 
    printvertical(root); 
  
    return 0; 
} 
