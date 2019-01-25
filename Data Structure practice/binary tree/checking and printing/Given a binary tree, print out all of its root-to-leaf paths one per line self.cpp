#include<iostream>
#include<vector>
#include <stdio.h> 
#include <stdlib.h> 
  using namespace std;
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
typedef struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}Node;
void printc(vector<node *>v)
{
	for(int i=0;i<v.size();i++)
	   cout<<v[i]->data<<" ";
	   cout<<"\n";
	   
}
void print(Node *root,vector<Node *> &v)
{
	if(root->left==NULL&root->right==NULL)
	{    v.push_back(root);
		printc(v);
		v.pop_back();
		return;
	}
	v.push_back(root);
	if(root->left)
	print(root->left,v);
	if(root->right)
	print(root->right,v);
	v.pop_back();
}
void printroottoleaves(Node *root)
{
	vector<Node *>v;
	print(root,v);
}
struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
} 
 
int main() 
{ 
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5);  
  
  /* Print all root-to-leaf paths of the input tree */
  printroottoleaves(root); 
  return 0; 
}
