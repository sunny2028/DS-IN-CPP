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
	g->adj[v].push_back(u);
}
void deletecheck(graph* g,int i,int v)
{
	g->adj[i].remove(v);
	g->adj[v].remove(i);
}
void dfsutil(graph *g,int v,int k)
{   
     list<int>::iterator itr;
     for(itr=g->adj[v].begin();itr!=g->adj[v].end();itr++)
     {   
     	deletecheck(g,*itr,v);
     	if(g->adj[*itr].size()<k)
     	    { 
			 dfsutil(g,*itr,k);
		    }
	 }
}
void dfs(graph* g,int k)
{
	for(int i=0;i<g->v;i++)
	{
		if(g->adj[i].size()<k)
		{
			dfsutil(g,i,k);
		
		}
	}

	for(int i=0;i<g->v;i++)
	{
		
			cout<<"head "<<i<<" -> ";
			 list<int>::iterator itr;
             for(itr=g->adj[i].begin();itr!=g->adj[i].end();itr++)
             cout<<*itr<<" ";
             cout<<"\n";
			
		
	}
}
int main()
{
graph *g=create(9);	
addedge(g,0,1);
addedge(g,0,2);
addedge(g,1,2);
addedge(g,1,5);
addedge(g,2,3);
addedge(g,2,4);
addedge(g,2,5);
addedge(g,2,6);
addedge(g,3,4);
addedge(g,3,6);
addedge(g,3,7);
addedge(g,4,6);
addedge(g,4,7);
addedge(g,5,6);
addedge(g,5,8);
addedge(g,6,7);
addedge(g,6,8);
dfs(g,3);
}
