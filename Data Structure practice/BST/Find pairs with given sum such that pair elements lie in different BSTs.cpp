
#include<bits/stdc++.h> 
using namespace std; 

// A binary Tree node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to create a new BST node 
// with key as given num 
struct Node* newNode(int num) 
{ 
	struct Node* temp = new Node; 
	temp->data = num; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to insert a given key to BST 
Node* insert(Node* root, int key) 
{ 
	if (root == NULL) 
		return newNode(key); 
	if (root->data > key) 
		root->left = insert(root->left, key); 
	else
		root->right = insert(root->right, key); 
	return root; 
} 

void PairSum(Node* root1,Node* root2,int sum)
{
	Node* curr1=root1;
	Node* curr2=root2;
	bool m1=false;
	bool m2=false;
	Node* temp1;
	Node* temp2;
	stack<Node*>s1;
	stack<Node*>s2;
	while(1)
	{
		while(m1==false)
		{
			if(curr1!=NULL)
			{
				s1.push(curr1);
				curr1=curr1->left;
			}
			else
			{   if(s1.empty())
			return;
				temp1=s1.top();
				s1.pop();
				curr1=temp1->right;
				m1=true;
			}
		}
		while(m2==false)
		{
			if(curr2!=NULL)
			{   
				s2.push(curr2);
				curr2=curr2->right;
			}
			else
			{  if(s2.empty())
			return;
				temp2=s2.top();
				s2.pop();
				curr2=temp2->left;
				m2=true;
			}
		}
		if(temp1->data+temp2->data==sum)
		{
			cout<<temp1->data<<"    "<<temp2->data<<"\n";
			m1=false;
			m2=false;
		}
		else if(temp1->data+temp2->data<sum)
		{
			m1=false;
		}
		else
		{
			m2=false;
		}
	}
}
 
int main() 
{ 
	// first BST 
	struct Node* root1 = NULL; 
	root1 = insert(root1, 8); 
	root1 = insert(root1, 10); 
	root1 = insert(root1, 3); 
	root1 = insert(root1, 6); 
	root1 = insert(root1, 1); 
	root1 = insert(root1, 5); 
	root1 = insert(root1, 7); 
	root1 = insert(root1, 14); 
	root1 = insert(root1, 13); 

	// second BST 
	struct Node* root2 = NULL; 
	root2 = insert(root2, 5); 
	root2 = insert(root2, 18); 
	root2 = insert(root2, 2); 
	root2 = insert(root2, 1); 
	root2 = insert(root2, 3); 
	root2 = insert(root2, 4); 

	int sum = 10; 
	PairSum(root1, root2, sum); 

	return 0; 
} 

