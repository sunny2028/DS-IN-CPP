#include<iostream>

/* A program to construct Binary Tree from preorder traversal */
#include<stdio.h> 
  
/* A binary tree node structure */
struct node 
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
  
/* Utility function to create a new Binary Tree node */
struct node* newNode (int data) 
{ 
    struct node *temp = new struct node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
  
/* A recursive function to create a Binary Tree from given pre[] 
   preLN[] arrays. The function returns root of tree. index_ptr is used 
   to update index values in recursive calls. index must be initially 
   passed as 0 */
struct node *createTree(int pre[], char preln[], int &i, int end) 
{ 
    if(i>end)
	return NULL;
	if(preln[i]=='L')
	{
		return newNode(pre[i]);
	}
	struct node *nn=newNode(pre[i]);
	i++;
	nn->left=createTree(pre,preln,i,end);
	i++;
	nn->right=createTree(pre,preln,i,end);
	return nn; 
} 
  
// A wrapper over constructTreeUtil() 
struct node *constructTree(int pre[], char preLN[], int n) 
{ 
    // Initialize index as 0. Value of index is used in recursion to maintain 
    // the current index in pre[] and preLN[] arrays. 
    int index = 0; 
  
    return createTree(pre, preLN, index, n); 
} 
  
  
/* This function is used only for testing */
void printInorder (struct node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder (node->left); 
  
    /* then print the data of node */
    printf("%d ", node->data); 
  
    /* now recur on right child */
    printInorder (node->right); 
} 
  
/* Driver function to test above functions */
int main() 
{ 
    struct node *root = NULL; 
  
    /* Constructing tree given in the above figure 
          10 
         /  \ 
        30   15 
       /  \ 
      20   5 */
    int pre[] = {10, 30, 20, 5, 15}; 
    char preLN[] = {'N', 'N', 'L', 'L', 'L'}; 
    int n = sizeof(pre)/sizeof(pre[0]); 
  
    // construct the above tree 
    root = constructTree (pre, preLN, n); 
  
    // Test the constructed tree 
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n"); 
    printInorder (root); 
  
    return 0; 
} 
