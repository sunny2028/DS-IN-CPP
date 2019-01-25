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
void linebylinelevelorder(node *root)
{   
	queue<node *>q;

	if(root)
	q.push(root);
	q.push(NULL);
	int count=0;
	while(q.size()>1)
	{
		node *temp=q.front();
		q.pop();
		if(temp==NULL)
		{ 
		    cout<<"\n";
			q.push(NULL);
		}
		else
		{  cout<<temp->data<<" ";
			if(temp->left)
			q.push(temp->left);
			if(temp->right)
			q.push(temp->right);
		}
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
    cout << "Spiral Order traversal of binary tree is \n";
    linebylinelevelorder(root);
 
    return 0;
}
