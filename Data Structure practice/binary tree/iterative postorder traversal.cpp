#include<bits/stdc++.h>
using namespace std;
struct tree
{int data;
tree *left;
tree *right;
};
tree *createnode(int data)
{
	tree *ptr=new tree;
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}
void postordertraversal(tree *root)
{
stack<tree *>s;
tree *previous=NULL;
do
{
	while(root)
	{
		s.push(root);
		root=root->left;
	}
	while(root==NULL&&!s.empty())
	{  root=s.top();
		if(root->right==NULL||root->right==previous)
		{
			cout<<s.top()->data<<" ";
			previous=s.top();
			s.pop();
			root=NULL;
		}
		else
		{
			root=root->right;
		}
	}
}while(!s.empty());
}
int main()
{
tree *root=createnode(1);
root->left=createnode(2);
root->right=createnode(3);
root->left->left=createnode(4);
root->left->right=createnode(5);
root->right->left=createnode(6);
root->right->right=createnode(7);
postordertraversal(root);
}
