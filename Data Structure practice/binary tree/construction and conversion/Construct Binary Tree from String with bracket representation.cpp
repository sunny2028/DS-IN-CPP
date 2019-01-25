
/* C++ program to construct a binary tree from  
   the given string */
#include <bits/stdc++.h> 
using namespace std; 
  
/* A binary tree node has data, pointer to left 
   child and a pointer to right child */
struct Node { 
    int data; 
    Node *left, *right; 
}; 
/* Helper function that allocates a new node */
Node* newNode(int data) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
/* This funtcion is here just to test  */
void preOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 
  

  
// function to construct tree from string 
Node* treeFromString(string str, int si, int ei) 
{ 
  stack<Node *>st;
  int num;
  for(int i=si;i<=ei;i++)
  {
  	if(str[i]>=48&&str[i]<=57)
  	{
  	 num=0;
  	 while(i<=ei&&str[i]>=48&&str[i]<=57)
  	 {
	  num=num*10+(str[i]-48);
	  i++;
     }
     i--;
     Node *temp=newNode(str[i]-48);
     st.push(temp);
     
	}
     if(str[i]==')')
	{
		Node *t=st.top();
		st.pop();
		if(st.top()->left==NULL)
		st.top()->left=t;
		else
		st.top()->right=t;
	}
  }
  return st.top();
} 
  
// Driver Code 
int main() 
{ 
    string str = "4(2(3)(1))(6(5)(7))"; 
    Node* root = treeFromString(str, 0, str.length() - 1); 
    preOrder(root); 
}
