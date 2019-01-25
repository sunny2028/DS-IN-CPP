#include<iostream> 
using namespace std; 
  
// To represents a node of a Binary Tree 
struct Node 
{ 
    struct Node *left, *right; 
    int data; 
};
Node *create(Node *root)
{
	if(root==NULL)
	return NULL;
	Node *left=create(root->left);
	Node *right=create(root->right);
	if(left)
	{
		left->right=root;
	}
	if(right)
	{
		right->left=root;
	}
	root->left=left;
	root->right=right;
	while(root->right)
	root=root->right;
	return root;
}
Node* bTreeToCList(Node *root)
{
	root=create(root);
	Node*temp=root;
	while(temp->left)
	temp=temp->left;
	temp->left=root;
	root->right=temp;
	return temp;
}
void displayCList(Node *head) 
{ 
    cout << "Circular Linked List is :\n"; 
    Node *itr = head; 
    do
    { 
        cout << itr->data <<" "; 
        itr = itr->right; 
    } while (head!=itr); 
    cout << "\n"; 
} 
  
  
// Create a new Node and return its address 
Node *newNode(int data) 
{ 
    Node *temp = new Node(); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Driver Program to test above function 
int main() 
{ 
    Node *root = newNode(10); 
    root->left = newNode(12); 
    root->right = newNode(15); 
    root->left->left = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36); 
  
    Node *head = bTreeToCList(root); 
    displayCList(head); 
    cout<<"\n"<<head->left->data;
  
    return 0; 
} 
