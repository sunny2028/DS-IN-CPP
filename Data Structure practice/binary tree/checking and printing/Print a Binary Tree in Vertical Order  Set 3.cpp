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
void printVerticalOrder(Node* root)
{
	queue<pair<Node *,int> >q;
	map<int,vector<int> > m;
	q.push(make_pair(root,0));
	while(!q.empty())
	{
		pair<Node *,int> p=q.front();
		q.pop();
		Node *temp=p.first;
		m[p.second].push_back(temp->key);
		if(temp->left)
		q.push(make_pair(temp->left,p.second-1));
		if(temp->right)
	    q.push(make_pair(temp->right,p.second+1));
	}
	map<int,vector<int> > ::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		for(int i=0;i<it->second.size();i++)
		{
			cout<<it->second[i]<<" ";\
		}
		cout<<"\n";
	}
}
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
