
#include <iostream> 
using namespace std; 

// BST Node 
struct Node 
{ 
	int key; 
	struct Node *left, *right; 
}; 
 
Node *newNode(int item) 
{ 
	Node *temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key) 
{ 
	if (node == NULL) return newNode(key); 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else
		node->right = insert(node->right, key); 
	return node; 
} 

Node* minvalue(Node* root)
{
    while(root->left)
    root=root->left;
    return root;
}
Node* maxvalue(Node* root)
{
    while(root->right)
    root=root->right;
    return root;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
while(root)
{
    if(root->key>key)
    {
        suc=root;
        root=root->left;
    }
    else if(root->key<key)
    {
        pre=root;
        root=root->right;
    }
    else
    break;
}
if(!root)
return ;
if(root->right)
{
    suc=minvalue(root->right);
}
if(root->left)
{
    pre=maxvalue(root->left);
}
return;
}

// Driver program to test above function 
int main() 
{ 
	int key = 65; //Key to be searched in BST 

/* Let us create following BST 
			50 
		/	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */
	Node *root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 


	Node* pre = NULL, *suc = NULL; 

	findPreSuc(root, pre, suc, key); 
	if (pre != NULL) 
	cout << "Predecessor is " << pre->key << endl; 
	else
	cout << "No Predecessor"; 

	if (suc != NULL) 
	cout << "Successor is " << suc->key; 
	else
	cout << "No Successor"; 
	return 0; 
} 

