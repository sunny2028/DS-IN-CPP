#include <iostream> 
#include <vector> 
#include <map>
#include<bits/stdc++.h> 
using namespace std; 
  
// Structure for a binary tree node 
struct Node 
{ 
    int key; 
    Node *left, *right; 
}; 
  
// A utility function to create a new node 
struct Node* newNode(int key) 
{ 
    struct Node* node = new Node; 
    node->key = key; 
    node->left = node->right = NULL; 
    return node; 
} 
void print(Node *root,map<int,vector<int> >&m,int h)
{
	if(root==NULL)
	return;
	m[h].push_back(root->key);
	print(root->left,m,h-1);
	print(root->right,m,h+1);
}
void printVerticalOrder(Node* root)
{
	map<int,vector<int> >m;
	int h=0;
	    print(root,m,h);
	    map<int,vector<int> >::iterator it;
	    for(it=m.begin();it!=m.end();it++)
	    {
	    	for(int i=0;i<it->second.size();i++)
	    	{
	    		cout<<it->second[i]<<" ";
			}
			cout<<"\n";
		}
}
  
// Driver program to test above functions 
int main() 
{ 
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    cout << "Vertical order traversal is \n"; 
    printVerticalOrder(root); 
    return 0; 
}
