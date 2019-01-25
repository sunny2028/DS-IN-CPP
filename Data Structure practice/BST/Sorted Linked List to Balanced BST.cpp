#include<iostream>
#include<stdio.h> 
#include<stdlib.h> 
  
  using namespace std;
/* Link list node */
struct LNode 
{ 
    int data; 
    struct LNode* next; 
}; 
  
/* A Binary Tree node */
struct TNode 
{ 
    int data; 
    struct TNode* left; 
    struct TNode* right; 
}; 
  
struct TNode* newNode(int data); 
int countLNodes(struct LNode *head); 
  
  TNode* util(LNode** head,int n)
  {
  	if(n<=0)
  	return NULL;
  	TNode* left=util(head,n/2);
  	TNode* root=newNode((*head)->data);
  	root->left=left;
  	*head=(*head)->next;
  	root->right=util(head,n-n/2-1);
  	return root;
  }
/* This function counts the number of nodes in Linked List and then calls 
   sortedListToBSTRecur() to construct BST */
struct TNode* sortedListToBST(struct LNode *head) 
{ 
  int n=countLNodes(head);
  return util(&head,n);
}

  
  
/* UTILITY FUNCTIONS */
  
/* A utility function that returns count of nodes in a given Linked List */
int countLNodes(struct LNode *head) 
{ 
    int count = 0; 
    struct LNode *temp = head; 
    while(temp) 
    { 
        temp = temp->next; 
        count++; 
    } 
    return count; 
} 
  
/* Function to insert a node at the beginging of the linked list */
void push(struct LNode** head_ref, int new_data) 
{ 
    /* allocate node */
    struct LNode* new_node = 
        (struct LNode*) malloc(sizeof(struct LNode)); 
    /* put in the data  */
    new_node->data  = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 
  
/* Function to print nodes in a given linked list */
void printList(struct LNode *node) 
{ 
    while(node!=NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct TNode* newNode(int data) 
{ 
    struct TNode* node = (struct TNode*) 
                         malloc(sizeof(struct TNode)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return node; 
} 
  
/* A utility function to print preorder traversal of BST */
void preOrder(struct TNode* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 
  
/* Drier program to test above functions*/
int main() 
{ 
    /* Start with the empty list */
    struct LNode* head = NULL; 
  
    /* Let us create a sorted linked list to test the functions 
     Created linked list will be 1->2->3->4->5->6->7 */
    push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 
  
    printf("\n Given Linked List "); 
    printList(head); 
  
    /* Convert List to BST */
    struct TNode *root = sortedListToBST(head); 
    printf("\n PreOrder Traversal of constructed BST "); 
    preOrder(root); 
  
    return 0; 
}
