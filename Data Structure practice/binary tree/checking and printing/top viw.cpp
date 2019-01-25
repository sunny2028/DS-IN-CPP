#include <bits/stdc++.h> 
using namespace std; 
  
// Structure of binary tree 
struct Node { 
    int data; 
    struct Node *left, *right; 
};
void topView(Node * root)
{ if(root==NULL)
     return;
	map<int,int>m;
	queue<pair<Node *,int> >q;
	q.push(make_pair(root,0));
	 while(!q.empty())
	{
	    pair<Node*, int> p = q.front(); 
        Node* temp = p.first; 
        int l = p.second; 
        q.pop(); 
	if (m.find(l) == m.end()) { 
            m[l] = temp->data; 
            
        }
		if(temp->left)
		q.push(make_pair(temp->left,l - 1));
		if(temp->right)
		q.push(make_pair(temp->right,l + 1));
	}
	map<int,int>::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		cout<<it->second<<" ";
	}
	
}
struct Node* newNode(int key) 
{ 
    struct Node* node = new Node; 
    node->data = key; 
    node->left = node->right = NULL; 
    return node; 
} 
  
// main function 
int main() 
{ 
    /* Create following Binary Tree 
             1 
           /  \ 
          2    3 
           \ 
            4 
             \ 
              5 
               \ 
                6*/
  
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->left->right->right = newNode(5); 
    root->left->right->right->right = newNode(6); 
  
    topView(root); 
    return 0; 
} 
  
