bool isCompleteBT(struct node* root)
{
    queue<node *>q;
q.push(root);
int flag=0;
while(!q.empty())
{
    node *temp=q.front();
    if(temp->left&&flag==0)
    q.push(temp->left);
    else if(temp->left&&flag==1)
    return false;
    else
    flag=1;
    if(temp->right&&flag==0)
    q.push(temp->right);
    else if(temp->right&&flag==1)
    return false;
    else
    flag=1;
    q.pop();
}
return true;
}
