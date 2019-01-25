#include<iostream>//https://www.geeksforgeeks.org/flattening-a-linked-list/
using namespace std;
struct node
{int data;
node *right;
node *down;
};
void push(node **head,int data)
{node *newnode=new node;
newnode->data=data;
newnode->right=NULL;
newnode->down=*head;
*head=newnode;
}
node *merge(node *a,node *b)
{if(a==NULL)
return b;
if(b==NULL)
return a;
node *result;
if(a->data < b->data)
{result=a;
result->down=merge(a->down,b);
}
else
{result=b;
result->down=merge(a,b->down);
}
return result;
}
node *flatten(node *root)
{if(root==NULL||root->right==NULL)
{return root;
}
return merge(root,flatten(root->right));
}
void display(node *root)
{
    while (root != NULL)
    {
        cout<<root->data<<" ";
        root=root->down;
    }
}
int main()
{node *root=NULL;
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );

    push( &( root->right ), 20 );
    push( &( root->right ), 10 );

    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );

    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );

    root=flatten(root);
    display(root);
}
