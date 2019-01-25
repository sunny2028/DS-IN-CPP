#include<bits/stdc++.h>
using namespace std;
bool dfs(int *arr,int *color,int n,int i)
{
	color[i]=1;
	int k=(i+arr[i]+n)%n;
	if(k==i)
	 {
	 	return false;
	 }
	 else if(color[k]==1)
	  {
	  return true;
      }
	  if(dfs(arr,color,n,k))
	  return true;
	  color[i]=2;
	  return false;
}
bool isCycle(int *arr,int n)
{
	int color[n];
	for(int i=0;i<n;i++)
	color[i]=0;
	for(int i=0;i<n;i++)
	{
		if(color[i]==0)
		if(	dfs(arr,color,n,i))
		return true;
	}

	return false;
}
int main(void) 
{ 
    int arr[] = {0};
    int n = sizeof(arr)/sizeof(arr[0]); 
    if (isCycle(arr, n)) 
        cout << "Yes"<<endl; 
    else
        cout << "No"<<endl; 
    return 0; 
} 
