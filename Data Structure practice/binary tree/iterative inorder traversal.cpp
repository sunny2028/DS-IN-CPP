#include<bits/stdc++.h>
using namespace std;
struct tree
{int data;
tree *left;
tree *right;
};
tree *createnode(int data)
{
	tree *ptr=new tree;
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}
void inordertraversal(tree *root)
{
	stack<tree *>s;
	while(1)
	{
		while(root)
		{
			s.push(root);
			root=root->left;
		}
		if(s.empty())
            break;
        root=s.top();
        s.pop();
        cout<<root->data<<"  ";
        root=root->right;
	}
}
int main()
{
tree *root=createnode(1);
root->left=createnode(2);
root->right=createnode(3);
root->left->left=createnode(4);
root->left->right=createnode(5);
root->right->left=createnode(6);
root->right->right=createnode(7);
inordertraversal(root);
}
