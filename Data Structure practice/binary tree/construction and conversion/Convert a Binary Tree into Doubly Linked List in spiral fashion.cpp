#include <bits/stdc++.h> 
using namespace std; 
  
// A Binary Tree Node 
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
};
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        cout << node->data << " "; 
        node = node->right; 
    } 
}
void spiralLevelOrder(Node *root)
{
	stack<Node *>s1;
	stack<Node *>s2;
	Node *prev=NULL;
	Node *head;
	s1.push(root);
	while(!s1.empty()||!s2.empty())
	{
		while(!s1.empty())
		{
			Node *temp=s1.top();
			s1.pop();
			if(temp->left)
			s2.push(temp->left);
			if(temp->right)
			s2.push(temp->right);
			if(prev==NULL)
			{    head=temp;
				temp->left=NULL;
				prev=temp;
			}
			else
			{
				prev->right=temp;
				temp->left=prev;
				prev=temp;
			}
		}
			while(!s2.empty())
		{
			Node *temp=s2.top();
			s2.pop();
			if(temp->right)
			s1.push(temp->right);
			if(temp->left)
			s1.push(temp->left);
			if(prev==NULL)
			{
				temp->left=NULL;
				prev=temp;
			}
			else
			{
				prev->right=temp;
				temp->left=prev;
				prev=temp;
			}
		}
	}
	printList(head);
}
Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create binary tree shown in above diagram 
    Node *root =  newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    //root->right->left->left  = newNode(12); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14); 
    //root->right->right->right  = newNode(15); 
  
    spiralLevelOrder(root); 
  
    return 0; 
} 

