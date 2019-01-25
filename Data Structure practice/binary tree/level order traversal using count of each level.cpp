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
int nodecount;
int count=0;
while(1)
{nodecount=q.size();
if(nodecount==0)
break;
while(nodecount>0)
{
	node *temp=q.front();
	q.pop();
	cout<<temp->data<<" ";
	if(temp->left)
	q.push(temp->left);
	if(temp->right)
	q.push(temp->right);
	nodecount--;
}
cout<<"\n";
	count++;
}
cout<<count;
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
