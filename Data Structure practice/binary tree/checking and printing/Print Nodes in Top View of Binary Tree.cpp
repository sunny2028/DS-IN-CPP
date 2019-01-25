#include <bits/stdc++.h> 
using namespace std; 
  
// Structure of binary tree 
struct Node { 
    int data; 
    struct Node *left, *right; 
}; 
  
// function should print the topView of 
// the binary tree 
void topView(struct Node* root) 
{ 
    if (root == NULL) 
        return; 
  
    map<int, int> m; 
    queue<pair<Node*, int> > q; 
  
    // push node and horizontal distance to queue 
    q.push(make_pair(root, 0)); 
  
    while (!q.empty()) { 
        pair<Node*, int> p = q.front(); 
        Node* temp = p.first; 
        int l = p.second; 
        q.pop(); 
  
        // if horizontal value is not in the hashmap 
        // that means it is the first value with that 
        // horizontal distance so print it and store 
        // this value in hashmap 
        if (m.find(l) == m.end()) { 
            m[l] = temp->data; 
            
        } 
  
        if (temp->left) 
            q.push(make_pair(temp->left, l - 1)); 
  
        if (temp->right) 
            q.push(make_pair(temp->right, l + 1)); 
    } 
    	map<int,int>::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		cout<<it->second<<" ";
	}
	
} 
  
// function to create a new node 
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
