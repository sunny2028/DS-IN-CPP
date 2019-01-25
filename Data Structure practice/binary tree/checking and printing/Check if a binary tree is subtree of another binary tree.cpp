
#include <iostream> 
#include <cstring> 
using namespace std; 
#define MAX 100 
  
// Structure of a tree node 
struct Node 
{ 
    char key; 
    struct Node *left, *right; 
}; 
  
// A utility function to create a new BST node 
Node *newNode(char item) 
{ 
    Node *temp =  new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
void inorder(Node *root,char *i,int &k)
{
	if(root==NULL)
	{
		i[k++]='$';
		return;
	}
	inorder(root->left,i,k);
	i[k++]=root->key;
	inorder(root->right,i,k);
}
void preorder(Node *root,char *i,int &k)
{
	if(root==NULL)
	{
		i[k++]='$';
		return;
	}
	i[k++]=root->key;
	preorder(root->left,i,k);
	preorder(root->right,i,k);
}
/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(Node *T, Node *S) 
{ char it[MAX],is[MAX];
int m=0,k=0;
  inorder(T,it,m);
  inorder(S,is,k);
  it[m]='\0';
  is[k]='\0';
  if(strstr(it,is)==NULL&&strstr(is,it)==NULL)
  return false;
  char pt[MAX],ps[MAX];
int m1=0,k1=0;
  preorder(T,pt,m1);
  preorder(S,ps,k1);
  pt[m1]='\0';
  ps[k1]='\0';
  return (strstr(pt,ps)!=NULL||strstr(ps,pt)!=NULL);
}
  
  
  
  
// Driver program to test above function 
int main() 
{ 
    Node *S = newNode('a'); 
    S->left = newNode('b'); 
    S->right = newNode('d'); 
    S->right->left = newNode('c'); 
    S->right->right = newNode('e'); 
  
    Node *T = newNode('d'); 
    T->left = newNode('c'); 
    //S->left->left = newNode('c'); 
    T->right = newNode('e'); 
  
    if (isSubtree(T, S)) 
        cout << "Yes: S is a subtree of T"; 
    else
        cout << "No: S is NOT a subtree of T"; 
  
    return 0; 
} 
