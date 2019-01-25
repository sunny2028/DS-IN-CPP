//int size(Node* root)
//{
//	if(root==NULL)
//	return 0;
//	return 1+size(root->left)+size(root->right);
//}
bool getCountutil(Node* root,int l,int h,int &c)
{
	if(root==NULL)
	return true;
	bool c1=getCount(root->left,int l,int h);
	bool c2=getcount(root->right,int l,int h);
	if(c1&&c2)
	{   
	if(root->data>=l&&root->data<=h)
	{
		c++;
		return true;
	}
   }
   return false;
}
int getCount(Node* root,int l,int h)
{
	int c=0;
	getCountutil(root,l,h,c);
	return c;
}
