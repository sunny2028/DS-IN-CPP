Node* util(Node* root,Node* temp,Node* succ)
{
	if(root==NULL)
	return NULL;
	if(root->data>temp->data)
	{
		succ=root;
		return util(root->left,temp,succ);
	}
	if(root->data<temp->data)
	{
		return util(root->right,temp,succ);
	}
	return succ;
}
Node* inordersuccer(Node* root,Node* temp)
{
	if(temp==NULL)
	return NULL;
	if(temp->rght!=NULL)
	return minvalue(root->right);
	Node* succ=NULL;
	return util(root,temp,succ);
}
