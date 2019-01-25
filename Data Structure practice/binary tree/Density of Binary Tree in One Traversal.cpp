#include<iostream>
#include<stdio.h> 
#include<stdlib.h> 
  using namespace std;
// A binary tree node 
struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 
  
// Helper function to allocates a new node 
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 
  static int count=0;
int density1(Node* root) 
{ 
  if(!root)
  return 0;
  count++;
   int left=density1(root->left);
   int right=density1(root->right);
   if(left>right)
   return 1+left;
   return 1+right;
    
} 
float density(Node* root)
{
	int h=density1(root);
	float c=(float)count/h;
	return c;
}

  
// Driver code to test above methods 
int main() 
{ 
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
  
    printf("Density of given binary tree is %f", 
           density(root)); 
  
    return 0; 
}
