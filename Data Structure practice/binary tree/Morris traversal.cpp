#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *left=NULL;
	Node *right=NULL;
	Node(int d)
	{
		data=d;
	}
};
Morristraversal(Node *curr)
{
	Node *prev;
	while(curr!=NULL)
	{
		if(curr->left==NULL)
		{
			cout<<curr->data<<" ";
			curr=curr->right;
		}
		else
		{
			prev=curr->left;
			while(prev->right!=NULL&&prev->right!=curr)
			prev=prev->right;
			if(prev->right==NULL)
			{
				prev->right=curr;
				curr=curr->left;
			}
			else
			{
				prev->right=NULL;
				cout<<curr->data<<" ";
				curr=curr->right;
			}
		}
	}
	
}
int main()
{
	struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
 
    Morristraversal(root);
    return 0;
}
