
// C++ program to construct a Binary Tree from parent array 
#include<bits/stdc++.h> 
using namespace std; 
  
// A tree node 
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// Utility function to create new Node 
Node *newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->key  = key; 
    temp->left  = temp->right = NULL; 
    return (temp); 
} 
  void create(int* parent,Node* created[],int i,int n,Node **root)
  {
  if(created[i]!=NULL)
  return;
  created[i]=newNode(i);
  if(parent[i]==-1)
    {
    	*root=created[i];
    	return;
	}
	if(created[parent[i]]==NULL)
	{
		create(parent,created,parent[i],n,root);
	}
	Node *q=created[parent[i]];
	if(q->left==NULL)
	q->left=created[i];
	else
	q->right=created[i];
  } 
  
Node *createTree(int parent[], int n) 
{ Node*  created[n];
  for(int i=0;i<n;i++)
    created[i]=NULL;
   Node *root=NULL;
  for(int i=0;i<n;i++)
  {
  	create(parent,created,i,n,&root);
  }
  return root;
}
//For adding new line in a program 
inline void newLine(){ 
    cout << "\n"; 
} 
  
// Utility function to do inorder traversal 
void inorder(Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout << root->key << " "; 
        inorder(root->right); 
    } 
} 
  
// Driver method 
int main() 
{ 
    int parent[] =  {-1, 0, 0, 1, 1, 3, 5}; 
    int n = sizeof parent / sizeof parent[0]; 
    Node *root = createTree(parent, n); 
    cout << "Inorder Traversal of constructed tree\n"; 
    inorder(root); 
    newLine(); 
}
