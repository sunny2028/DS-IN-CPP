#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};
node* newNode(int data) 
{ 
    node* new_node = new node; 
    new_node->data = data; 
    new_node->left = new_node->right = NULL; 
    return (new_node); 
} 
  
/* Function to print nodes in a given doubly linked list */
void printList(node *node) 
{ 
    while (node!=NULL) 
    { 
        printf("%d ", node->data); 
        node = node->right; 
    } 
} 
node* binarytreeutil(node *root)
{
	if(root->left!=NULL)
	{
		node *left=binarytreeutil(root->left);
		while(left->right)
		{
		left=left->right;
	    }
	    root->left=left;
	    left->right=root;
		
	}
	if(root->right!=NULL)
	{
		node *right=binarytreeutil(root->right);
		for(;right->left!=NULL;right=right->left);
		root->right=right;
		right->left=root;
	}
	return root;
}
node* bintree2list(node *root)
{
	root=binarytreeutil(root);
	while(root->left)
	{
		root=root->left;
	}
	return root;
}
//void treeToList(node* root,node*& prev, node*& head)
//{
//	if(root)
//	{
//		treeToList(root->left,prev,head);
//		if(prev)
//			prev->right = root;
//		else
//			head = root;
//		root->left= prev;
//		prev = root;
//		treeToList(root->right,prev,head);
//	}
//}
//void BToDLL(Node* root, Node** head_ref) 
//{ 
//    // Base cases 
//    if (root == NULL) 
//        return; 
//  
//    // Recursively convert right subtree 
//    BToDLL(root->right, head_ref); 
//  
//    // insert root into DLL 
//    root->right = *head_ref; 
//  
//    // Change left pointer of previous head 
//    if (*head_ref != NULL) 
//        (*head_ref)->left = root; 
//  
//    // Change head of Doubly linked list 
//    *head_ref = root; 
//  
//    // Recursively convert left subtree 
//    BToDLL(root->left, head_ref); 
//}
  
int main() 
{ 
    // Let us create the tree shown in above diagram 
    node *root        = newNode(10); 
    root->left        = newNode(12); 
    root->right       = newNode(15); 
    root->left->left  = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36); 
  
    // Convert to DLL 
    node *head = bintree2list(root); 
  
    // Print the converted list 
    printList(head); 
  
    return 0; 
} 
