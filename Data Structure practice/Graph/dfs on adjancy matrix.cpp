#include<bits/stdc++.h>
using namespace std;
struct graph
{
	int u;
	int v;
	int **Adj;
};
graph* adjancymatrix()
{   
     int x,y,v,u;
	graph *g=new graph;
	cin>>v>>u;
	g->v=v;
	g->u=u;
	g->Adj=new int*[v];
	for(int i=0;i<g->v;i++)
	{    g->Adj[i]=new int[v];
		for(int j=0;j<g->v;j++)
    	g->Adj[i][j]=0;
    } 
	for(int i=0;i<g->u;i++)
	{
		cin>>x>>y;
		g->Adj[x][y]=1;
	}
	return g;
}
void dfsutil(int *visited,graph* g,int i)
{
	visited[i]=1;
	cout<<i;
	for(int j=0;j<g->v;j++)
	{
		if(!visited[j]&&g->Adj[i][j])
		{
			dfsutil(visited,g,j);
		}
	}
}
void dfs(graph *g)
{       
	int visited[g->v];
	for(int i=0;i<g->v;i++)
	visited[i]=0;
	for(int i=0;i<g->v;i++)
	{
		if(!visited[i])
		dfsutil(visited,g,i);
	}
}
int main()
{
	graph *g=adjancymatrix();
	dfs(g);
}
