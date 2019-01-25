void fun1(vector<Tnode*>&v,int min,int max)
{
	if(min>=max)
	return;
	static int x=1;
	 tnode* nn=newnode(x);
	 nn->left=fun(v,min,x);
}
fun(int n)
{
	vector<Tnode*>v;
	fun1(v,min,max);
}
