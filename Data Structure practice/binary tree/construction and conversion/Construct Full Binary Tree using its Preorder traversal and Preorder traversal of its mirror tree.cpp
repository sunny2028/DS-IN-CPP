
/* program for construction of full binary tree */
#include <stdio.h> 
#include <stdlib.h> 
  
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
  static int index=0;
struct node *constructTreeUtil(int *pre,int *post,int l,int h)
{
	if(l>h)
	return NULL;
	node *nn=newNode(pre[index++]);
	if(l==h)
	return nn;
	int i;
	for(i=l;i<=h;i++)
	{
		if(post[i]==pre[index])
		break;
	}
	if(i<=h)
	{
		nn->left=constructTreeUtil(pre,post,i,h);
		nn->right=constructTreeUtil(pre,post,l+1,i-1);
	}
	return nn;
	
}
struct node *constructTree (int pre[], int post[], int size) 
{ return constructTreeUtil(pre,post,0,size-1);
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
    int pre[] ={1,2,4,5,3,6,7};
    int post[] ={1,3,7,6,2,5,4};  
    int size = sizeof( pre ) / sizeof( pre[0] ); 
  
    struct node *root = constructTree(pre, post, size); 
  
    printf("Inorder traversal of the constructed tree: \n"); 
    printInorder(root); 
  
    return 0; 
}
