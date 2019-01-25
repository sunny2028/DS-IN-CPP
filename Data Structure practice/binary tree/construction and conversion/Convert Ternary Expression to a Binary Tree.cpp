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
Node *convertExpression(string str) 
{ stack<Node *>st;
   Node *temp=newNode(str[0]);
   st.push(temp);
   Node *tt= new Node;
   int flag=1;
   for(int i=1;str[i];i++)
   {
       if(str[i]=='?')
       {
           Node *temp1=newNode(str[++i]);
           st.top()->left=temp1;
           st.push(temp1);
       }
       else if(str[i]==':')
       {
           st.pop();
           Node *temp2=newNode(str[++i]);
           st.top()->right=temp2;
           if(st.size()==1&&flag)
           {tt=st.top();
           flag=0;
           }
           st.pop();
           st.push(temp2);
       }
   }
   return tt;
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
    string expression = "w?l?r?b?b:m:q?b:h:c?d?a:r:z?o:w:k?k?y?h:i:d?d:q:s?c?d:x:r?j:m"; 
    Node *root = convertExpression(expression); 
    printTree(root) ; 
    return 0; 
}
