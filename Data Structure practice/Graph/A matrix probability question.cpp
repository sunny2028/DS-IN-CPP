#include<bits/stdc++.h>
using namespace std;
void dfs(int m,int n,int i,int j,int N,int &count,int &count1,int step)
{
	if(i<0||i>=m||j<0||j>=n)
	{
		count1++;
		return;
	}
	if(step==N)
	{
		count++;
		return;
	}
	dfs(m,n,i-1,j,N,count,count1,step+1);
	dfs(m,n,i+1,j,N,count,count1,step+1);
	dfs(m,n,i,j-1,N,count,count1,step+1);
	dfs(m,n,i,j+1,N,count,count1,step+1);
}
double findProbability(int m,int n,int i,int j,int N)
{   int count=0;int count1=0;
	dfs(m,n,i,j,N,count,count1,0);
	cout<<count<<" "<<count1;
	return (double)(count-count1)/count;
}
int main() 
{ 
    // matrix size 
    int m = 5, n = 5; 
  
    // coordinates of starting point 
    int i = 1, j = 1; 
  
    // Number of steps 
    int N = 2; 
  
    cout << "Probability is "
        << findProbability(m, n, i, j, N); 
  
    return 0; 
}
