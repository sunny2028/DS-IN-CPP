#include<bits/stdc++.h>
using namespace std;
#define N 4
int MinimumPath(int M[][N],int a,int b,int x,int y)
{
	int arr[][2]={{1,0},{-1,0},{0,1},{0,-1}};
	queue<pair<int,int> >q;
	q.push(make_pair(a,b));
	q.push(make_pair(INT_MAX,INT_MAX));
	int count=0;
	bool visited[N][N];
	memset(visited,false,sizeof(visited));
	while(q.size()>1)
	{
		pair<int,int>p=q.front();
		q.pop();
		if(p.first==INT_MAX&&p.second==INT_MAX)
		{
			count++;
			q.push(p);
			continue;
		}
		if(p.first==x&&p.second==y)
		  return count;
		  visited[p.first][p.second]=true;
		for(int i=0;i<4;i++)
		{
			int newi=arr[i][0]+p.first;
			int newj=arr[i][1]+p.second;
			if(newi>=0&&newi<N&&newj>=0&&newj<N&&visited[newi][newj]==false&&M[newi][newj]==3)
			{
	       	q.push(make_pair(newi,newj));
		    }
		}
	}
	return -1;
}
int main() 
{ 
    int M[N][N] = {{ 3 , 3 , 3 , 0 }, 
        { 3 , 0 , 3 , 3 }, 
        { 3 , 3 , 0 , 3 }, 
        { 0 , 3 , 3 , 3 } 
    }; 
  
    cout << MinimumPath(M,0,2,2,0) << endl; 
  
    return 0; 
} 
