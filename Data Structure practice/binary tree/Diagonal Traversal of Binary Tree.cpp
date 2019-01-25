#include <bits/stdc++.h> 
using namespace std; 
  
// Tree node 
struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 
  
void diagonalPrint(Node *root)
{
	queue<Node*>q;
	Node *temp=root;
	while(temp)
	{
		q.push(temp);
		temp=temp->right;
	}
	q.push(NULL);
	while(q.size()>1)
	{
		temp=q.front();
		if(temp)
		{
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left)
		{
			temp=temp->left;
			while(temp)
			{
		     q.push(temp);
		     temp=temp->right;
			}
		}
	    }
	    else
	    {
	    	cout<<"\n";
	    	q.pop();
	    	q.push(NULL);
		}
	}
}
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 
  
// Driver program 
int main() 
{ 
    Node* root = newNode(19);
root->left = newNode(3);
root->right = newNode(10);
root->left->right = newNode(6);
root->right->left = newNode(14);
root->right->left->left = newNode(13);
root->left->right->right= newNode(4);
root->left->right->right->right = newNode(7); 
  
    /*  Node* root = newNode(1); 
        root->left = newNode(2); 
        root->right = newNode(3); 
        root->left->left = newNode(9); 
        root->left->right = newNode(6); 
        root->right->left = newNode(4); 
        root->right->right = newNode(5); 
        root->right->left->right = newNode(7); 
        root->right->left->left = newNode(12); 
        root->left->right->left = newNode(11); 
        root->left->left->right = newNode(10);*/
  
    diagonalPrint(root); 
  
    return 0; 
} 
