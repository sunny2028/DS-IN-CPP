#include<iostream>
#include<vector>
using namespace std;
struct Node 
{
	int data;
	Node *left;
	Node *right;
};
void preorder(Node *root)
{
	if(root==NULL)
	{
		return;
	}
  
  preorder(root->left);
  cout<<root->data<<" ";
  preorder(root->right);
  
}
vector<Node *> getTrees(int in[],int start,int end)
{ vector<Node *>tree;
	if(start>end)
	{tree.push_back(NULL);
	return tree;
	}
	for(int i=start;i<=end;i++)
	{
		vector<Node *>ltree=getTrees(in,start,i-1);
		vector<Node *>rtree=getTrees(in,i+1,end);
		for(int j=0;j<ltree.size();j++)
		{
			for(int k=0;k<rtree.size();k++)
			{
				Node *newnode=new Node;
				newnode->data=in[i];
				newnode->left=ltree[j];
				newnode->right=rtree[k];
				tree.push_back(newnode);
			}
		}
	}
	return tree;
}
int main()
{
	int in[] = {4, 5, 7};
    int n = sizeof(in) / sizeof(in[0]);
  
    vector<Node *> trees = getTrees(in, 0, n-1);
  
    cout << "Preorder traversals of different "
         << "possible Binary Trees are \n";
    for (int i = 0; i < trees.size(); i++)
    {
        preorder(trees[i]);
        printf("\n");
    }
    return 0;
}
