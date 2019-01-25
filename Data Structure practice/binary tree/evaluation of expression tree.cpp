#include<bits/stdc++.h>
using namespace std;
struct node 
{
	string data;
	node *left=NULL;
	node *right=NULL;
	node(string a)
	{
	  data=a;
	}
	
};
int toint(string s)
{
	int val=0,i=0;
	while(s[i])
	{
		val=val*10+(s[i]-48);
		i++;
	}
	return val;
}
int eval(node *root)
{  
	if(root->left==NULL&&root->right==NULL)
	  return toint(root->data);
	  int t,t1;
	 t=eval(root->left);
	 t1=eval(root->right);
	if(root->data=="*")
	return t*t1;
		if(root->data=="+")
	return t+t1;
		if(root->data=="-")
	return t-t1;
		if(root->data=="/")
	return t/t1;
		if(root->data=="^")
	return t^t1;
	
}
int main()
{
	node *root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("20");
    cout << eval(root) << endl;
 
    delete(root);
 
    root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("/");
    root->right->right->left = new node("20");
    root->right->right->right = new node("2");
 
    cout << eval(root);
    return 0;
	
}
