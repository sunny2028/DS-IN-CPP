#include<bits/stdc++.h>
using namespace std;
  
// Structure of a BST Node 
struct node 
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
struct node* newNode (int data) 
{ 
    struct node *temp = new struct node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
  
/* A utility function to print Inoder traversal of a Binary Tree */
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
void merge(node* root1, node* root2)
{
	stack<node*>s1;
	stack<node*>s2;
	node* curr1=root1;
	node* curr2=root2;
	if(!curr1)
	{
	inorder(curr2);
	return; 
    }
if(!curr2)
{
	inorder(curr1);
	return;
}
	
	while(curr1||curr2||!s1.empty()||!s2.empty())
	{
		if(curr1||curr2)
		{
			if(curr1)
			{
				s1.push(curr1);
				curr1=curr1->left;
			}
			if(curr2)
			{
				s2.push(curr2);
				curr2=curr2->left;
			}
			
		}
		else
		{
		if(s1.empty())
			{
				while(!s2.empty())
				{
					curr2=s2.top();
					curr2->left=NULL;
					inorder(curr2);
					s2.pop();
				}
				return;
			}
			if(s2.empty())
			{
					while(!s1.empty())
				{
					curr1=s1.top();
					curr1->left=NULL;
					inorder(curr1);
					s1.pop();
				}
				return;
			}
			curr1=s1.top();
			curr2=s2.top();
			if(curr1->data<curr2->data)
			{
				cout<<curr1->data<<" ";
				curr1=curr1->right;
				s1.pop();
				curr2=NULL;
			}
			else
			{
				
				cout<<curr2->data<<" ";
				curr2=curr2->right;
				s2.pop();
				curr1=NULL;
			}	
		}
		
	}
}
int main() 
{ 
    struct node  *root1 = NULL, *root2 = NULL; 
  
    /* Let us create the following tree as first tree 
            3 
          /  \ 
         1    5 
     */
    root1 = newNode(3); 
    root1->left = newNode(1); 
    root1->right = newNode(5); 
  
    /* Let us create the following tree as second tree 
            4 
          /  \ 
         2    6 
     */
    root2 = newNode(4); 
    root2->left = newNode(2); 
    root2->right = newNode(6); 
  
    // Print sorted nodes of both trees 
    merge(root1, root2); 
  
    return 0; 
} 
