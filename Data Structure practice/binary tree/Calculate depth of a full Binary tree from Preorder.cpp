#include <bits/stdc++.h> 
using namespace std;
 int find(char *tree,int &i,int n)
 {
 	if(i>=n||tree[i]=='l')
 	return 0;
 	i++;
 	int left=find(tree,i,n);
 	i++;
 	int right=find(tree,i,n);
 	return max(left,right)+1;
 }
int findDepth(char* tree,int n)
{
	int i=0;
    return find(tree,i,n);
}
int main() 
{ 
    // Your C++ Code 
    char tree[] = "nlnnlll"; 
    int n = strlen(tree); 
  
    cout << findDepth(tree, n) << endl; 
  
    return 0; 
}
