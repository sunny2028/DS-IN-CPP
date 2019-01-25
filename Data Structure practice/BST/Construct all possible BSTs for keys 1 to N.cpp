// A C++ prgroam to contrcut all unique BSTs for keys from 1 to n 
#include <iostream> 
#include<vector> 
using namespace std; 

// node structure 
struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
	struct node *temp = new node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to do preorder traversal of BST 
void preorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		cout << root->key << " "; 
		preorder(root->left); 
		preorder(root->right); 
	} 
} 

// function for constructing trees 
vector<struct node *> constructTrees(int start, int end) 
{ 
	vector<node* >list;
	if(start>end)
	{
		list.push_back(NULL);
		return list;
	}
	for(int i=start;i<=end;i++)
	{
		
		vector<node*>left=constructTrees(start,i-1);
		vector<node*>right=constructTrees(i+1,end);
		for(int j=0;j<left.size();j++)
		{
			for(int k=0;k<right.size();k++)
			{node *nn=newNode(i);
				nn->left=left[j];
				nn->right=right[k];
				list.push_back(nn);
			}
		}
		
	}
	return list;
} 

// Driver Program to test above functions 
int main() 
{ 
	// Construct all possible BSTs 
	vector<struct node *> totalTreesFrom1toN = constructTrees(1, 3); 


	/* Printing preorder traversal of all constructed BSTs */
	cout << "Preorder traversals of all constructed BSTs are \n"; 
	for (int i = 0; i < totalTreesFrom1toN.size(); i++) 
	{ 
		preorder(totalTreesFrom1toN[i]); 
		cout << endl; 
	} 
	return 0; 
} 

