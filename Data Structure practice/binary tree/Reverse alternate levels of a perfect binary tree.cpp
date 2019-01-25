#include<bits/stdc++.h> 
#define MAX 100 
using namespace std; 
  
// A Binary Tree node 
struct Node 
{ 
    char data; 
    struct Node *left, *right; 
}; 
  
// A utility function to create a new Binary Tree Node 
struct Node *newNode(char item) 
{ 
    struct Node *temp =  new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
void printInorder(struct Node *root) 
{ 
    if (root == NULL) return; 
    printInorder(root->left); 
    cout << root->data << " "; 
    printInorder(root->right); 
} 
void store(Node *root,int l,int &index,char *arr)
{
	if(root)
	{
		store(root->left,l+1,index,arr);
		if(l%2==1)
		{
			arr[index++]=root->data;
		}
		store(root->right,l+1,index,arr);
	}
}
void reversealt(Node *root,char *arr,int &index,int l)
{
	
	if(root)
	{
	reversealt(root->left,arr,index,l+1);
	if(l%2==1)
	{
		root->data=arr[index++];
	}
	reversealt(root->right,arr,index,l+1);
    }
}
void reverseAlternate(Node *root)
{
	char *arr=new char[MAX];
	int index=0;
	store(root,0,index,arr);
	reverse(arr,arr+index);
	index=0;
	reversealt(root,arr,index,0);
}
  
// Driver Program to test above functions 
int main() 
{ 
    struct Node *root = newNode('a'); 
    root->left = newNode('b'); 
    root->right = newNode('c'); 
    root->left->left = newNode('d'); 
    root->left->right = newNode('e'); 
    root->right->left = newNode('f'); 
    root->right->right = newNode('g'); 
    root->left->left->left = newNode('h'); 
    root->left->left->right = newNode('i'); 
    root->left->right->left = newNode('j'); 
    root->left->right->right = newNode('k'); 
    root->right->left->left = newNode('l'); 
    root->right->left->right = newNode('m'); 
    root->right->right->left = newNode('n'); 
    root->right->right->right = newNode('o'); 
  
    cout << "Inorder Traversal of given tree\n"; 
    printInorder(root); 
  
    reverseAlternate(root); 
  
    cout << "\n\nInorder Traversal of modified tree\n"; 
    printInorder(root); 
  
    return 0; 
} 
