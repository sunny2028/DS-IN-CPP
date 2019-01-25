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
void deletelast(tree *root,tree *dnode)
{
queue<tree *>q;
q.push(root);
while(!q.empty())
{
	tree *temp=q.front();
	q.pop();
	if(temp->left)
	{
		if(temp->left==dnode)
		{
			temp->left=NULL;
			delete(dnode);
			break;
		}
		q.push(temp->left);
	}
	if(temp->right)
	{
		if(temp->right==dnode)
		{
			temp->right=NULL;
			delete(dnode);
			break;
		}
		q.push(temp->right);
	}
}
}
void deletenode(tree *root,int x)
{
	queue<tree *>q;
q.push(root);
tree *node;
tree *temp;
while(!q.empty())
{
	temp=q.front();
	q.pop();
	if(temp->data==x)
	node=temp;
	if(temp->left)
	q.push(temp->left);
	if(temp->right)
	q.push(temp->right);
}
int data=temp->data;
node->data=data;
deletelast(root,temp);
}
void levelordertraversal(tree *root)
{
queue<tree *>q;
q.push(root);
while(!q.empty())
{
	tree *temp=q.front();
	cout<<temp->data<<" ";
	q.pop();
	if(temp->left)
	q.push(temp->left);
	if(temp->right)
	q.push(temp->right);
}
}
int main()
{
tree *root=createnode(1);
root->left=createnode(2);
root->right=createnode(3);
root->left->left=createnode(4);
root->right->left=createnode(6);
root->right->right=createnode(7);
levelordertraversal(root);
cout<<"\n";
deletenode(root,4);
levelordertraversal(root);
}
