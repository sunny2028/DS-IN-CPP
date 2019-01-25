Tnode* constructutil(Node *head,int min,int max)
{   if(min>max||head==NULL)
return NULL;
    Node* temp=head;
	int mid=(min+max)/2;
	for(int i=min;i<mid+min-1;i++)
	temp=temp->next;
	Tnode *newnode=newTnode(temp->key);
	if(min==max)
	return newnode;
	newnode->left=constructutil(head,min,mid-1);
	newnode->right=constructutil(temp->next,mid+1,max);
	return newnode;
}
Tnode* construct(Node *head)
{
	int count =countNodes(head);
	int min=1;
	int max=count;
	return constructutil(head,min,max);
}
Tnode* constructutil(Node **head,int n)
{
	if(n<=0)
	return NULL;
	Tnode* left=constructutil(head,n/2);
	Tnode* newnode=new Tnode;
	newnode->data=(*head)->data;
	newnode->left=left;
	*head=(*head)->next;
	newnode->right=constructutil(head,n-n/2-1)
	return newnode;
	
}
Tnode* construct(Node *head)
{
	int count=countNodes(head);
	return constructutil(&head,n);
}
