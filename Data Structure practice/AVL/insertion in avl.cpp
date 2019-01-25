#include<bits/stdc++.h>
using namespace std;
struct avltree
{
	int data;
	int height;
	avltree* left;
	avltree* right;
};
int height(avltree *node)
{
	if(node==NULL)
	return 0;
 return node->height;
}
avltree* singlerotateright(avltree* x)
{
	avltree* w=x->right;
	x->right=w->left;
	w->left=x;
	x->height=max(height(x->left),height(x->right))+1;
	w->height=max(height(w->right),x->height)+1;
	return w;
}

avltree* singlerotateleft(avltree* x)
{
	avltree* w=x->left;
	x->left=w->right;
	w->right=x;
	x->height=max(height(x->left),height(x->right))+1;
	w->height=max(height(w->left),x->height)+1;
	return w;
}
avltree* doublerotateleftright(avltree *x)
{
	
	x->left=singlerotateright(x->left);
	return singlerotateleft(x);
}
avltree* doublerotaterightleft(avltree *x)
{
	x->right=singlerotateleft(x->right);
	return singlerotateright(x);
}
int getbalance(avltree* root)
{
	if(root==NULL)
	return 0;
	return height(root->left)-height(root->right);
}
avltree* findmin(avltree* root)
{
	while(root->left)
	{
		root=root->left;
	}
	return root;
}
avltree* insert(avltree* root,int data)
{
	if(!root)
	{
		root=new avltree;
		root->data=data;
		root->height=0;
		root->left=root->right=NULL;
	}
	else if(root->data>data)
	{
		root->left=insert(root->left,data);
		if(height(root->left)-height(root->right)==2)
		{
			if(data<root->left->data)
			{
				root=singlerotateleft(root);
			}
			else
			{
				root=doublerotateleftright(root);
			}
		}
	}
	else if(root->data<data)
	{
		root->right=insert(root->right,data);
	
		if(height(root->right)-height(root->left)==2)
		{
			if(data>root->right->data)
			root=singlerotateright(root);
		else
		{
			root=doublerotaterightleft(root);
		}
	    }
	}
	root->height=max(height(root->left),height(root->right))+1;
	return root;
}
avltree* deletenode(avltree* root,int data)
{
	if(root==NULL)
	return NULL;
	if(root->data<data)
	{
		root->right=deletenode(root->right,data);
	}
   else	if(root->data>data)
	{
		root->left=deletenode(root->left,data);
	
	}
	else
	{
		if(root->left==NULL||root->right==NULL)
		{
		avltree* temp=root->left? root->left:root->right;
		if(temp==NULL)
		{
			temp=root;
			root=NULL;
		}
		else
		{
			*root=*temp;
		}
		delete temp;
		}
		else
		{
			avltree* temp=findmin(root->right);
			root->data=temp->data;
			root->right=deletenode(root->right,temp->data);
		}
	}
	if(root==NULL)
	return root;
		root->height=max(height(root->left),height(root->right))+1;
	int balance=getbalance(root);
	if(balance>1&&getbalance(root->left)>=0)
	   root=singlerotateleft(root);
	else if(balance>1&&getbalance(root->left)<0)
	   root=doublerotateleftright(root);
	   else if(balance<-1&&getbalance(root->right)<=0)
	   root=singlerotateright(root);
	   else if(balance<-1&&getbalance(root->right)>0)
	   root=doublerotaterightleft(root);
	   return root;
}
void preorder(avltree* root)
{
	if(root)
	{
		cout<<root->data<<"  ";
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	avltree* root=NULL;
    root = insert(root, 9); 
    root = insert(root, 5); 
    root = insert(root, 10); 
    root = insert(root, 0); 
    root = insert(root, 6); 
    root = insert(root, 11); 
    root = insert(root, -1); 
    root = insert(root, 1); 
    root = insert(root, 2); 
  preorder(root);
  root=deletenode(root,10);
  cout<<"\n";
  preorder(root);
}
