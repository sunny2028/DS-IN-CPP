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
void postordertraversal(tree *root)
{
stack<tree *>s;
tree *curr=root;
tree *temp;
while(!(curr==NULL&&s.empty()))
{
	if(curr)
	{
	s.push(curr);
    curr=curr->left;
    }
	else
	{
	temp=s.top()->right;
	if(temp==NULL)
	{
		cout<<s.top()->data<<" ";
		temp=s.top();
		s.pop();
	while(!s.empty()&&s.top()->right==temp)
	  {
	  	temp=s.top();
	  	cout<<temp->data<<" ";
	  	s.pop();
	  }	
	}
	else
	curr=temp;
   }
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
postordertraversal(root);
}
