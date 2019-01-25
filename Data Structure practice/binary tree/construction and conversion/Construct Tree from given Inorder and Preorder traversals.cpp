

#include <stdio.h> 
#include <stdlib.h> 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
typedef struct node { 
    char data; 
    struct node* left; 
    struct node* right; 
}Node; 
int search(char *in,int s,int e,char c)
{
	for(int i=s;i<=e;i++)
	{
		if(in[i]==c)
		  return i;
	}

	return -1;
}
struct node* newNode(char data);
static int index=0;
Node* buildTree(char* in,char *pre,int st, int end)
{ 
	if(st>end)
	  return NULL;
	   
	  int ind=search(in,st,end,pre[index++]);
	  Node *left=buildTree(in,pre,st,ind-1);
	  Node *right=buildTree(in,pre,ind+1,end);
	  Node *nn=newNode(in[ind]);
	  nn->left=left;
	  nn->right=right;
	  
	  return nn;
	  
}

struct node* newNode(char data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
  
/* This funtcion is here just to test buildTree() */
void printInorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    printf("%c ", node->data); 
  
    /* now recur on right child */
    printInorder(node->right); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
  char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
    int len = sizeof(in) / sizeof(in[0]); 
    struct node* root = buildTree(in, pre, 0, len - 1); 
  
    /* Let us test the built tree by printing Insorder traversal */
    printf("Inorder traversal of the constructed tree is \n"); 
    printInorder(root); 
} 
