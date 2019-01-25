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
}
void dfsutil(graph *g,int *visited,int v)
{    visited[v]=1;
     list<int>::iterator itr;
     for(itr=g->adj[v].begin();itr!=g->adj[v].end();itr++)
     {
     	if(!visited[*itr])
     	dfsutil(g,visited,*itr);
	 }
}
int mothervertex(graph* g)
{
	int visited[g->v];
	int x;
	memset(visited,0,sizeof(int)*g->v);
	for(int i=0;i<g->v;i++)
	{
		if(!visited[i])
		{
	   dfsutil(g,visited,i);
	   x=i;
        }
    }
    	memset(visited,0,sizeof(int)*g->v);
    	dfsutil(g,visited,x);
    	for(int i=0;i<g->v;i++)
    	{
    		if(visited[i]==false)
    		return -1;
		}
    return x;
}
int main()
{
graph *g=create(7);	
addedge(g,0,1);
addedge(g,0,2);
addedge(g,1,3);
addedge(g,4,1);
addedge(g,6,4);
addedge(g,5,6);
addedge(g,5,2);
addedge(g,6,0);
cout<<mothervertex(g);
}
