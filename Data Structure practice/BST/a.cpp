inorder(int arr[],int low,int high,int size)
{
	static int x=0;
	if(x>=size||low>high)
	return NULL;
	Node *root=NULL;
	if(root->data>min&&root->data<high)
	{
		root=newnode(arr[x]);
		x++;
	root->left=inorder(arr,low,root->data,size);
	root->right=inorder(arr,root->data,high,size);	
	}
	return root;
	
}
