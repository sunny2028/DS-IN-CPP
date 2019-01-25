#include<bits/stdc++.h>
using namespace std;
struct et
{
char data;
et *left;
et *right;	
};
et * createnode(char a)
{
	et *newnode= new et;
	newnode->data=a;
	newnode->left=newnode->right=NULL;
	return newnode;
}
bool isoperand(char a)
{
	return (a>='a'&&a<='z'||a>='A'&&a>='Z');
          
}
void infix(et *root)
{
	if(!root)
	return;
	infix(root->left);
	cout<<root->data;
	infix(root->right);
}
et *convert(char *exp)
{
	stack<et *>st;
	for(int i=0;exp[i];i++)
	{
		et *newnode=createnode(exp[i]);
	if(isoperand(exp[i]))
	{
		st.push(newnode);
	}
	else
	{
		et *a=st.top();
		st.pop();
		et *b=st.top();
		st.pop();
		newnode->right=a;
		newnode->left=b;
		st.push(newnode);
	}
	}
	return st.top();
}

int main()
{
	char exp[]="ab+ef*g*-";
	et *root=convert(exp);
	infix(root);
}
