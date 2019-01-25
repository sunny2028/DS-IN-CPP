/* program to construct tree using inorder and levelorder traversals */
#include <iostream> 
using namespace std; 
  
/* A binary tree node */
struct Node 
{ 
    int key; 
    struct Node* left, *right; 
}; 
Node* newNode(int key) 
{ 
    Node *node = new Node; 
    node->key = key; 
    node->left = node->right = NULL; 
    return (node); 
} 
int search(int *in,int s,int e,int k)
{
	for(int i=s;i<=e;i++)
	{
		if(in[i]==k)
		return i;
	}
	return -1;
}

int *extract(int *in,int *level,int m,int n)
{
	int *temp=new int[m];
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(search(in,0,m-1,level[i])!=-1)
		{
			temp[j++]=level[i];
		}
	}
	return temp;
}
Node *buildTree(int *in,int *level,int st,int end,int n)
{    if(st>end)
      return NULL;
	int ind=search(in,st,end,level[0]);
	int *ltree=extract(in,level,ind,n);
	int *rtree=extract(in+ind+1,level,n-ind-1,n);
	Node *root=new Node;
	root->key=in[ind];
	root->left=buildTree(in,ltree,st,ind-1,n);
	root->right=buildTree(in,rtree,ind+1,end,n);
	return root;
}
  

  
/* Uti;ity function to print inorder traversal of binary tree */
void printInorder(Node* node) 
{ 
    if (node == NULL) 
       return; 
    printInorder(node->left); 
    cout << node->key << " "; 
    printInorder(node->right); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int in[]    = {4, 8, 10, 12, 14, 20, 22}; 
    int level[] = {20, 8, 22, 4, 12, 10, 14}; 
    int n = sizeof(in)/sizeof(in[0]); 
    Node *root = buildTree(in, level, 0, n - 1, n); 
  
    /* Let us test the built tree by printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n"; 
    printInorder(root); 
  
    return 0; 
} 
