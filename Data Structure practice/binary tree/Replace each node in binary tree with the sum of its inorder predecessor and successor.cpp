#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left=NULL;
	Node *right=NULL;
};
Node* getNode(int data)
{
	Node *newnode=new Node;
	newnode->data=data;
	return newnode;
}
void preorder(Node *root)
{
	if(root==NULL)
	{
		return;
	}
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
  
}
void sum(Node *root)
{ stack<Node *>st;
    vector<Node *>v;
	while(1)
	{ while(root)
	{
		st.push(root);
		root=root->left;
	}
	if(st.empty())
     break;
      root=st.top();
      st.pop();
	 v.push_back(root);
	 root=root->right;		
	}
	//cout<<"fsefew";
	int curr=0,j;
	for(j=0;j<v.size()-1;j++)
	{
		Node *t=v[j];
		int l=t->data;
		t->data=curr+v[j+1]->data;
	    curr=l;
	}
	v[j]->data=curr;
	
}
int main()
{
	struct Node* root = getNode(1); /*         1        */
    root->left = getNode(2);        /*       /   \      */
    root->right = getNode(3);       /*     2      3     */
    root->left->left = getNode(4);  /*    /  \  /   \   */
    root->left->right = getNode(5); /*   4   5  6   7   */
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    preorder(root);
    cout<<"\n";
    sum(root);
    preorder(root);
}
