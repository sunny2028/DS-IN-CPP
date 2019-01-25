#include <iostream>
#include <queue>
#include <stack>
using namespace std;
 
// A Binary Tree Node
struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void modifiedLevelOrder(Node *root)
{
queue<Node*>q;
stack<Node*>s;
bool rtl=false;
int ct=0,size;
while(!q.empty())
{
	ct++;
	size=q.size();
	for(int i=0;i<size;i++)
	{
	Node *temp=q.front();
	q.pop();
	if(rtl)
	s.push(temp);
	else
	cout<<temp->data<<" ";
	if(temp->left)
	q.push(temp->left);
	if(temp->right)
	q.push(temp->right); 
	}
	if(rtl)
	{
		while(!s.empty())
		{
			cout<<s.top();
			s.pop();
		}
	}
	if(ct==2)
	{
		rtl=!rtl;
		ct=0;
	}
cout<<"\n";
}
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(2);
    root->left->right->left->left = newNode(16);
    root->left->right->left->right = newNode(17);
    root->right->left->right->left = newNode(18);
    root->right->right->left->right = newNode(19);
 
    modifiedLevelOrder(root);
 
    return 0;
}
