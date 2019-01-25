//generate HB(0)
int count=0;
avltree* build(int h)
{
	if(h==0)
	return NULL;
	avltree* temp=new avltree;
	temp->left=build(h-1);
	temp->data=count++;
	temp->right=build(h-1);
	return temp;
}
avltree* build(int l,int r)
{
if(l>r)
return NULL;
int m=l+(r-l)/2;
avltree* temp=new avltree;
temp->data=m;
temp->left=build(l,m-1);
temp->right=build(m+1,r);
return temp;
}	
