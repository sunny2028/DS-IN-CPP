#include <bits/stdc++.h> 
using namespace std; 
  
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node { 
    int data; 
    struct Node *left, *right; 
}; 
  
/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
void postorder(struct Node* head) 
{ 
   Node *temp=head;
   set<Node *>s;
   while(temp&&s.find(temp)==s.end())
   {
   	if(temp->left&&s.find(temp->left)==s.end())
   	temp=temp->left;
   	else if(temp->right&&s.find(temp->right)==s.end())
   	temp=temp->right;
   	else
   	{
   	cout<<temp->data<<" ";
   	s.insert(temp);
	temp=head;	
	}
   }
} 
  
struct Node* newNode(int data) 
{ 
    struct Node* node = new Node; 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return (node); 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    struct Node* root = newNode(8); 
    root->left = newNode(3); 
    root->right = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
    postorder(root); 
    return 0; 
} 
