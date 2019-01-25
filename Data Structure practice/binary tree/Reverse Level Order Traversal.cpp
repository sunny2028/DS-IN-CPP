#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void reverseLevelOrder(node *root)
{
	vector<node *>v;
	v.push_back(root);
	int i=0;
	while(i<v.size())
	{
		node *t=v[i];
		if(t->left)
		v.push_back(t->left);
		if(t->right)
		v.push_back(t->right);
		i++;
	}
	int j=v.size()-1;
	while(j>=0)
	{
		cout<<v[j]->data<<" ";
		j--;
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
