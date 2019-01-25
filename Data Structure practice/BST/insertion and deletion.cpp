#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left=NULL;
	node *right=NULL;
};
bool search(node *root,int item)
{
	if(root==NULL)
	return false;
	if(root->data==item)
	return true;
	if(root->data>item)
	return search(root->left,item);
	return search(root->right,item);
}
void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
node *insert(node *root,int item)
{
	if(root==NULL)
	{
		node *nn=new node;
		nn->data=item;
		return nn;
	}
	else if(root->data<item)
	{
		root->right=insert(root->right,item);
	}
	else
	root->left=insert(root->left,item);
	return root;
}
int findmax(node *root)
{
	while(root->right)
	{
	root=root->right;	
	}
	return root->data;
}
node *del(node *root,int item)
{    if(!root)
return NULL;

	if(root->data==item)
	{
		if(root->right==NULL)
		return root->left;
		if(!root->left)
		return root->right;
		else
		{
			int x=findmax(root->left);
			root->data=x;
			root->left=del(root->left,x);
		}
	}
	else if(root->data>item)
      root->left=del(root->left,item);
      else
      root->right=del(root->right,item);
      return root;
}
int maxi(node *root)
{
	if(!root)
	return INT_MIN;
	while(root->right)
	{
		root=root->right;
	}
	return root->data;
}
int mini(node *root)
{
	if(!root)
	return INT_MAX;
	while(root->left)
	{
		root=root->left;
	}
	return root->data;
}
bool isbalanced(node* root)
{
	if(root==NULL)
	return true;
	int ma=maxi(root->left);
	int mi=mini(root->right);
	if(!(root->data>ma&&root->data<mi))
	return false;
	else
	return isbalanced(root->left)&&isbalanced(root->right);
	
}
bool isbalancedbst(node *root,int max,int min)
{    if(root==NULL)
return true;
	if(!(root->data>min&&root->data<max))
	return false;
	return  isbalancedbst(root->left,root->data,min)&&isbalancedbst(root->right,max,root->data);
}
node* lca(node *root,int n1,int n2)
{
	if(root==NULL||root->data==n1||root->data==n2)
	return root;
	node *l=lca(root->left,n1,n2);
	node *r=lca(root->right,n1,n2);
	if(l&&r)
	return root;
	if(l)
	return l;
	if(r)
	return r;

}

int main()
{   
     node *root=NULL;
	int arr[]={5,7,2,9,4,8,3,6,1};
	for(int i=0;i<=8;i++)
	{
		root=insert(root,arr[i]);
    }
	inorder(root);
	cout<<"\n";
	root=del(root,1);
	inorder(root);
	cout<<"\n";
		root=del(root,4);
	inorder(root);
	cout<<"\n";
		root=del(root,5);
	inorder(root);
	cout<<"\n";
	cout<<search(root,9);
	cout<<"\n"<<isbalanced(root);
	cout<<"\n"<<isbalancedbst(root,INT_MAX,INT_MIN);
	node *j=lca(root,2,8);
	cout<<"\n"<<j->data;
}

