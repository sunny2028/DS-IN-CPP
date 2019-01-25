#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void reverseLevelOrder(node *root)
{
	queue<node*>q;
	stack<int>s;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		s.push(temp->data);
		if(temp->right)
		q.push(temp->right);
		if(temp->left)
		q.push(temp->left);
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
struct node* newNode(int data)
{    struct node *Node=new node;
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return(Node);
}
 
/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
 
    printf("Level Order traversal of binary tree is \n");
    reverseLevelOrder(root);
 
    return 0;
}
