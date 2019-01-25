#include<bits/stdc++.h>
using namespace std;
struct graph
{
	int v;
	list<int> *adj;
};
graph * create(int v)
{
	graph *g=new graph;
	g->v=v;
	g->adj=new list<int>[v];
	return g;
}
void addedge(graph *g,int u,int v)
{
	g->adj[u].push_back(v);
//	g->adj[v].push_back(u);
}
void dfsutil(graph *g,int *visited,int v)
{    visited[v]=1;
	cout<<v;
     list<int>::iterator itr;
     for(itr=g->adj[v].begin();itr!=g->adj[v].end();itr++)
     {
     	if(!visited[*itr])
     	dfsutil(g,visited,*itr);
	 }
}
void dfs(graph* g,int v)
{
	int visited[g->v];
	memset(visited,0,sizeof(int)*g->v);
	dfsutil(g,visited,v);
}
int main()
{
graph *g=create(4);	
addedge(g,0,1);
addedge(g,0,2);
addedge(g,1,2);
addedge(g,2,0);
addedge(g,2,3);
addedge(g,3,3);
dfs(g,2);
}
