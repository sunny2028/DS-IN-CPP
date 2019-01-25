#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *left=NULL;
	node *right=NULL;
};
node *newNode(int d)
{
	node *newnode=new node;
	newnode->data=d;
	return newnode;
}
int height(node *root)
{
	if(root==NULL)
	return 0;
	int lheight=height(root->left);
	int rheight=height(root->right);
	return 1+max(lheight,rheight);
}
void check(node *root,int i)
{
	if(root==NULL)
	return;
	if(i==1)
	cout<<root->data<<" ";
	else
	{
		check(root->left,i-1);
		check(root->right,i-1);
	}
}
void linebylinelevelorder(node *root)
{   
int h=height(root);
for(int i=1;i<=h;i++)
{
	check(root,i);
	cout<<"\n";
}
}
int main()
{
	 struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    cout << "level Order traversal of binary tree is \n";
    linebylinelevelorder(root);
 
    return 0;
}
