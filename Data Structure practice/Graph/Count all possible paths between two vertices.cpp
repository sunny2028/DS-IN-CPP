#include<bits/stdc++.h>
using namespace std;
struct graph
{
	int v;
	list<int> *adj;
};;
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
void dfsutil(graph *g,int *visited,int src,int dest,int &count)
{    visited[src]=1;
      if(src==dest)
        count++;
        else
		{
     list<int>::iterator itr;
     for(itr=g->adj[src].begin();itr!=g->adj[src].end();itr++)
     {
     	if(!visited[*itr])
     	dfsutil(g,visited,*itr,dest,count);
	 }
}
	 visited[src]=0;
	 
}
void dfs(graph* g,int src,int dest)
{
	int visited[g->v];
	memset(visited,0,sizeof(int)*g->v);
	int count;
	   dfsutil(g,visited,src,dest,count);
	   cout<<count;
}
int main()
{
graph *g=create(4);	
addedge(g,0,1);
addedge(g,0,2);
addedge(g,0,3);
addedge(g,2,0);
addedge(g,2,1);
addedge(g,1,3);
dfs(g,2,3);
}
