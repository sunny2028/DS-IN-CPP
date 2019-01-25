#include<bits/stdc++.h>
using namespace std;
int solve(int *arr,int n)
{
	int parent[n];
	bool visited[n];
	memset(parent,-1,sizeof(parent));
	memset(visited,false,sizeof(visited));
	int count=0;
	for(int i=0;i<n;i++)
	{    int j=i;
		if(parent[j]==-1)
		{
			while(parent[j]==-1)
			{
				parent[j]=i;
				j=(j+arr[j])%n+1;
			}
			if(parent[j]==i)
			{
				while(!visited[j])
				{
					visited[j]=true;
					count++;
					j=(j+arr[j])%n+1;
				}
			}
		}
	}
	return count;
}
int main() 
{ 
    int A[] = { 0, 0, 0, 2 }; 
    int n = sizeof(A) / sizeof(A[0]); 
    cout << solve(A, n); 
    return 0; 
} 
