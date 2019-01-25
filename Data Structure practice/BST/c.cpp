static int sum=0;
if(root==NULL)
return;
check(root->right);
int temp=root->data;
root->data=sum;
sum=sum+temp;
check(root->left);
