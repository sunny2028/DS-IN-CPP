int count=0;
avltree* generateavl(int h)
{
	if(h==0)
	return NULL;
	avltree* temp=new avltree;
	temp->data=count++;
	temp->left=generateavl(h-1);
	temp->right=generateavl(h-2);
	temp->height=h;
	return temp;
}
5478j0
