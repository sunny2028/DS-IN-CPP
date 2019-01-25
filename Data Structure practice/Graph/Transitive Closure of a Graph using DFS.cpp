#include<bits/stdc++.h>
using namespace std;
struct graph
{
	int v;
	list<int> *adj;
	bool **check;
};
graph * create(int v)
{
	graph *g=new graph;
	g->v=v;
	g->adj=new list<int>[v];
	g->check=new bool*[g->v];
	for(int i=0;i<v;i++)
	{
		g->check[i]=new bool[g->v];
		memset(g->check[i],false,g->v*sizeof(bool));
	}
	return g;
}
void addedge(graph *g,int u,int v)
{
	g->adj[u].push_back(v);
}
void dfsutil(graph *g,int u,int v)
{    g->check[u][v]=true;
     list<int>::iterator itr;
     for(itr=g->adj[v].begin();itr!=g->adj[v].end();itr++)
     {
     	if(!g->check[u][*itr])
     	{
		 dfsutil(g,u,*itr);
	    }
	 }
}
void transitiveenclosure(graph* g)
{
	for(int i=0;i<g->v;i++)
	   dfsutil(g,i,i);
	for(int i=0;i<g->v;i++)
	{
		for(int j=0;j<g->v;j++)
		 cout<<g->check[i][j]<<" ";
		 cout<<"\n";
	}
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
transitiveenclosure(g);
}
