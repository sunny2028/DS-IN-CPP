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
void  modifiedLevelOrder(node *root)
{
	stack<node *>s;
	queue<node *>q;
    if(root==NULL)
    return;
    s.push(root);
    bool flag=true;
    bool flag1=true;
    while(!s.empty()||!q.empty())
    {
    	if(flag)
    	{
    			while(!s.empty())
    	{
    		node *temp=s.top();
    		s.pop();
    		cout<<temp->data<<" ";
    			if(temp->left)
    		q.push(temp->left);
    		if(temp->right)
    		q.push(temp->right);		
		}
		}
		else
		{
    	while(!s.empty())
    	{
    		node *temp=s.top();
    		s.pop();
    		cout<<temp->data<<" ";
    		if(temp->right)
    		q.push(temp->right);
    		if(temp->left)
    		q.push(temp->left);
    		
    		
		}
	}
	flag=!flag;
		cout<<"\n";
		if(flag1)
		{
		while(!q.empty())
		{
			node *temp=q.front();
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left)
			s.push(temp->left);
			if(temp->right)
			s.push(temp->right);
		}
    }
    else
    {
    	while(!q.empty())
		{
			node *temp=q.front();
			q.pop();
			cout<<temp->data<<" ";
				if(temp->right)
			s.push(temp->right);
			if(temp->left)
			s.push(temp->left);
		
		}
	}
    flag1=!flag1;
		cout<<"\n";
	}
}
int main()
{
    
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(2);
    root->left->right->left->left = newNode(16);
    root->left->right->left->right = newNode(17);
    root->right->left->right->left = newNode(18);
    root->right->right->left->right = newNode(19);
 
    modifiedLevelOrder(root);
 
    return 0;
}
