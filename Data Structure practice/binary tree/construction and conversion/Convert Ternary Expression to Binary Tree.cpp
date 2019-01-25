// C++ program to covert a ternary expreesion to 
// a tree. 
#include<bits/stdc++.h> 
using namespace std; 

// tree structure 
struct Node 
{ 
	char data; 
	Node *left, *right; 
}; 

// function create a new node 
Node *newNode(char Data) 
{ 
	Node *new_node = new Node; 
	new_node->data = Data; 
	new_node->left = new_node->right = NULL; 
	return new_node; 
} 

// Function to convert Ternary Expression to a Binary 
// Tree. It return the root of tree 
Node *convertExpression(string expression, int &i) 
{ 

	// Base case 
	if (i >= expression.size()) 
		return NULL; 

	// store current character of expression_string 
	// [ 'a' to 'z'] 
	Node *root = newNode(expression[i]); 

	// Move ahead in str 
	++i; 
	if(i>=expression.size()||expression[i]==':')
	return root;

	// if current character of ternary expression is '?' 
	// then we add next character as a left child of 
	// current node 
	if (i < expression.size() && expression.at(i)=='?') 
	{	i++;
	    root->left = convertExpression(expression, i);
	}

	// else we have to add it as a right child of 
	// current node expression.at(0) == ':' 
	 if (i < expression.size()) 
	{	i++;
	    root->right = convertExpression(expression, i); 
}
	return root; 
} 

// function print tree 
void printTree( Node *root) 
{ 
	if (!root) 
		return ; 
			cout << root->data <<" "; 
	printTree(root->left); 
	

	printTree(root->right); 
} 

// Driver program to test above function 
int main() 
{ 
	string expression = "w?f?r?x:s:j?y:b:l?d?b:e:f?s:a"; 
	int i=0;
	Node *root = convertExpression(expression, i); 
	printTree(root) ; 
	return 0; 
} 

