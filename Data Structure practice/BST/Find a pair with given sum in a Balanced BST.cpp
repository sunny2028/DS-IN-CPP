/* In a balanced binary search tree isPairPresent two element which sums to 
a given value time O(n) space O(logn) */
#include <stdio.h> 
#include <stdlib.h> 
#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100 

// A BST node 
struct node 
{ 
	int val; 
	struct node *left, *right; 
}; 

// Stack type 
struct Stack 
{ 
	int size; 
	int top; 
	struct node* *array; 
}; 

// A utility function to create a stack of given size 
struct Stack* createStack(int size) 
{ 
	struct Stack* stack = 
		(struct Stack*) malloc(sizeof(struct Stack)); 
	stack->size = size; 
	stack->top = -1; 
	stack->array = 
		(struct node**) malloc(stack->size * sizeof(struct node*)); 
	return stack; 
} 

// BASIC OPERATIONS OF STACK 
int isFull(struct Stack* stack) 
{ return stack->top - 1 == stack->size; } 

int isEmpty(struct Stack* stack) 
{ return stack->top == -1; } 

void push(struct Stack* stack, struct node* node) 
{ 
	if (isFull(stack)) 
		return; 
	stack->array[++stack->top] = node; 
} 

struct node* pop(struct Stack* stack) 
{ 
	if (isEmpty(stack)) 
		return NULL; 
	return stack->array[stack->top--]; 
} 

// Returns true if a pair with target sum exists in BST, otherwise false 
bool isPairPresent(struct node *root, int target) 
{ 
	bool done1=false;
 bool done2=false;
 stack<node*>s1;
 stack<node*>s2;
 node* curr1=root;
 node* curr2=root;
 node* temp=NULL;
 node* temp1=NULL;
 while(1)
 {  
 	while(done1==false)
 	{  
 		if(curr1!=NULL)
 		{
 		s1.push(curr1);
		 curr1=curr1->left;	
		}
		else
		{ 
		  if(s1.empty())
		       done1=true;
		       else
		       {
		       	 
			temp=s1.top();
			s1.pop();
			curr1=temp->right;
			done1=true;
		
		       }
		}
	}
	
	while(done2==false)
	{
		if(curr2!=NULL)
		{
			s2.push(curr2);
			curr2=curr2->right;
		}
		else
		{     if(s2.empty())
		        done2=true;
		        else
		        {
			temp1=s2.top();
			s2.pop();
			curr2=temp1->left;
			done2=true;
			    }
		}
	}
	if(temp!=temp1&&temp->val+temp1->val==target)
	{    cout<<"Pair found"<<temp->val<<" + "<<temp1->val<<" = "<<target;
		return true;
	}
	if(temp->val+temp1->val<target)
	{
		done1=false;
	}
	else if(temp->val+temp1->val>target)
	{
		done2=false;
	}
	if(temp->val>=temp1->val)
	return false;
	
	
 }
 return false;
} 

// A utility function to create BST node 
struct node * NewNode(int val) 
{ 
	struct node *tmp = (struct node *)malloc(sizeof(struct node)); 
	tmp->val = val; 
	tmp->right = tmp->left =NULL; 
	return tmp; 
} 

// Driver program to test above functions 
int main() 
{ 
	/* 
				15 
				/	 \ 
			10	 20 
			/ \	 / \ 
			8 12 16 25 */
	struct node *root = NewNode(15); 
	root->left = NewNode(10); 
	root->right = NewNode(20); 
	root->left->left = NewNode(8); 
	root->left->right = NewNode(12); 
	root->right->left = NewNode(16); 
	root->right->right = NewNode(25); 

	int target = 33; 
	if (isPairPresent(root, target) == false) 
		printf("\n No such values are found\n");  
	return 0; 
} 

