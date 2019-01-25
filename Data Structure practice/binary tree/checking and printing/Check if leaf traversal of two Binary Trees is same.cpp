#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node *right;
};
Node *newnode(int a)
{
	Node *nn= new Node;
	nn->data=a;
	nn->left=nn->right=NULL;
	return nn;
}
bool isleaf(Node *root)
{
	if(root->left==NULL&&root->right==NULL)
	return true;
	return false;
}
bool ischeck(Node *root,Node *root1)
{
	stack<Node *>s;
	stack<Node *>s1;
	s.push(root);
	s1.push(root1);
	while(!s.empty()||!s1.empty())
	{
		if(s.empty()||s1.empty())
		return false;
		Node *temp=s.top();
		s.pop();
		while(temp!=NULL&&!isleaf(temp))
		{
			if(temp->right)
			s.push(temp->right);
			if(temp->left)
			s.push(temp->left);
			if(s.empty())
			{
				temp=NULL;
			}
			else
			{
			temp=s.top();
			s.pop();
		    }
		}
		Node *temp1=s1.top();
		s1.pop();
		while(temp1!=NULL&&!isleaf(temp1))
		{
			if(temp1->right)
			s1.push(temp1->right);
			if(temp1->left)
			s1.push(temp1->left);
			if(s1.empty())
			{
				temp1=NULL;
			}
			else
			{
			temp1=s1.top();
			s1.pop();
		    }
		}
//		if(temp1==NULL&&temp==NULL)
//		return false;
		if(temp&&!temp1)
		return false;
		if(!temp&&temp1)
		return false;
		if(temp&&temp1)
		{
			if(temp->data!=temp1->data)
			return false;
		}
	}
	return true;
}
int main()
{
	Node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->right->left=newnode(5);
	root->right->right=newnode(6);
	Node *root1=newnode(0);
	root1->left=newnode(8);
	root1->right=newnode(3);
	root1->left->right=newnode(4);
	root1->right->left=newnode(5);
	root1->right->right=newnode(6);
	ischeck(root,root)?cout<<"yes":cout<<"no";
}

