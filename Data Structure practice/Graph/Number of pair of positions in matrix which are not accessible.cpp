#include<bits/stdc++.h>
using namespace std;
void insertgraph(vector<int> *v ,int a,int b,int x,int y,int N)
{
int c=(a-1)*N+b;
int z=(x-1)*N+y;
v[c].push_back(z);
v[z].push_back(c);
}
void dfs(vector<int> *v,bool *visited,int n,int &count)
{

	for(int i=0;i<v[n].size();i++)
	{
		if(!visited[v[n][i]])
		{    count++;
		visited[v[n][i]]=true;
			dfs(v,visited,v[n][i],count);
		}
	}
}
int calculate(vector<int> *v,int N)
{   int n=N*N+1;
	bool visited[n];
	int ans=0;
	memset(visited,false,sizeof(visited));
	for(int i=1;i<n;i++)
	{
		if(!visited[i])
		{ 
		visited[i]=true;
		int count=1;
		dfs(v,visited,i,count);
		ans+=count*(N*N-count);
	    }
	}
	return ans;
}
int main()
{    int N=2;
	vector<int> v[N*N+1];
	insertgraph(v,1,1,1,2,N);
	insertgraph(v,1,2,2,2,N);
	cout<<calculate(v,N);
}
