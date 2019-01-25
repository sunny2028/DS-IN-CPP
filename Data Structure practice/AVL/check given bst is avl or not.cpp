int check(avltree* root)
{
	if(root==NULL)
	return 0;
	int left=check(root->left)
	if(left==-1)
	return -1;
	int right=check(root->right);
	if(right==-1)
	return -1;
	if(abs(left-right)>1)
	return -1;
	return 1+max(left,right);
}
