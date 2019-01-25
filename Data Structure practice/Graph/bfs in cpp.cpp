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
void bfs(graph* g,int v)
{
	int visited[g->v];
	memset(visited,0,sizeof(int)*g->v);
	queue<int>q;
	q.push(v);
	visited[v]=1;

	while(!q.empty())
	{
      int t=q.front();
	  q.pop();
	  	
	  cout<<t;
	  list<int>::iterator itr;
	  for(itr=g->adj[t].begin();itr!=g->adj[t].end();itr++)
	  {
	  	if(!visited[*itr])
	  	{
	  		visited[*itr]=1;
	        q.push(*itr);
		}
	  } 		
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
bfs(g,2);
}
