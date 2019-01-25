#include<bits/stdc++.h>
#include <stdio.h> 
#include <stdlib.h> 
  using namespace std;
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
  
// A utility function to create a node 
struct node* newNode (int data) 
{ 
    struct node* temp = (struct node *) malloc( sizeof(struct node) ); 
  
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 
  
//
//  node* constructtreeutil(int pre[],int low,int high,int size)
//  {
//  	static int x=0;
//  	if(x>=size||low>high)
//  	return NULL;
//  	node* nn=new node;
//  	nn->data=pre[x];
//  	nn->left=NULL;
//  	nn->right=NULL;
//  	x++;
//  	if(low==high)
//  	return nn;
//  	int i;
//  	for(i=low;i<=high;i++)
//  	{
//  	if(pre[i]>nn->data)
//	  break;
//	  	
//	}
//  	nn->left=constructtreeutil(pre,x,i-1,size);
//  	nn->right=constructtreeutil(pre,i,high,size);
//  	return nn;
//  }
//// The main function to construct BST from given preorder traversal. 
//// This function mainly uses constructTreeUtil() 
//struct node *constructTree (int pre[], int size) 
//{ 
//return constructtreeutil(pre,0,size-1,size);   
//}
struct node *constructTree (int pre[], int size) 
{stack<node*>s;
node* root=newNode(pre[0]);
s.push(newNode(pre[0]));
for(int i=1;i<size;i++)
{
node* temp=NULL;
while(!s.empty()&&pre[i]>s.top()->data)
{
	temp=s.top();
	s.pop();
}
if(temp==NULL)
{
  node* t=newNode(pre[i]);
  s.top()->left=t;
  s.push(t);
}
else
{
	temp->right=newNode(pre[i]);
	s.push(temp->right);
}
}
return root;
}
  
// A utility function to print inorder traversal of a Binary Tree 
void printInorder (struct node* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    printf("%d ", node->data); 
    printInorder(node->right); 
} 
  
// Driver program to test above functions 
int main () 
{ 
    int pre[] = {10, 5, 1, 7, 40, 50}; 
    int size = sizeof( pre ) / sizeof( pre[0] ); 
  
    struct node *root = constructTree(pre, size); 
  
    printf("Inorder traversal of the constructed tree: \n"); 
    printInorder(root); 
  
    return 0; 
}
