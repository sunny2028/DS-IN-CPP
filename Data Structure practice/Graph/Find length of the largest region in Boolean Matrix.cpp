#include<bits/stdc++.h>
using namespace std;
#define COL 5
void dfs(int M[][COL],int m,int n,int r,int &size,bool visited[][COL])
{    visited[m][n]=true;
     size++;
	int a[][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
	for(int i=0;i<8;i++)
	{
		int newi=a[i][0]+m;
		int newj=a[i][1]+n;
		if(newi>=0&&newi<r&&newj>=0&&newj<COL&&M[newi][newj]&&!visited[newi][newj])
		{
			dfs(M,newi,newj,r,size,visited);
		}
	}
	
}
int largestRegion(int M[][COL])
{ 	cout<<sizeof(M)<<"c  ";
	int r=sizeof(M)/sizeof(M[0]);
	bool visited[r][COL];
	int max=0;
	for(int i=0;i<r;i++)
	memset(visited[i],false,sizeof(bool)*COL);
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<COL;j++)
		{
			if(!visited[i][j]&&M[i][j])
			{   cout<<"j " ;
			    int size=0;
				dfs(M,i,j,r,size,visited);
				if(size>max)
				max=size;
				
			}
		}
	}
	return max;
	
}
int main() 
{ 
    int M[][COL] = { {0, 0, 1, 1, 0}, 
                     {1, 0, 1, 1, 0}, 
                     {0, 1, 0, 0, 0}, 
                     {0, 0, 0, 0, 1}}; 
  
    cout << largestRegion(M); 
  
    return 0; 
} 
