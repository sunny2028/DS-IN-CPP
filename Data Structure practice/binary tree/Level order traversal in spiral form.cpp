#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *left=NULL;
	node *right=NULL;
};
void check(stack<node *>&s,stack<node *>&s1)
{
		while(!s.empty())
		{
		node *t=s.top();
		s.pop();
		cout<<t->data<<" ";
		if(t->right)
		s1.push(t->right);
		if(t->left)
		s1.push(t->left);
	    }
}
void check1(stack<node *>&s,stack<node *>&s1)
{
		while(!s.empty())
		{
		node *t=s.top();
		s.pop();
		cout<<t->data<<" ";
		if(t->left)
		s1.push(t->left);
		if(t->right)
		s1.push(t->right);
	    }
}
void printSpiral(node *root)
{
	stack<node *>s;
	stack<node *>s1;
	s.push(root);
	bool flag=true;
	while(!s.empty())
	{   
	if(flag)
	   check(s,s1);
	   else
	   check1(s,s1);
    flag=!flag;
	    stack<node*>temp=s;
	    s=s1;
	    s1=temp;
	    
	}
}
node *newNode(int d)
{
	node *newnode=new node;
	newnode->data=d;
	return newnode;
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
    printSpiral(root);
 
    return 0;
}
