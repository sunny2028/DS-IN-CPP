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
void bfs(graph* g,int v)
{
	queue<pair<int,int> >q;
	q.push(make_pair(0,1));
	int level=0;
	while(!q.empty())
	{
      pair<int,int>p=q.front();
	  q.pop();
	  int t=p.first;
	  int b=p.second;
	  if(b==v)
	  cout<<t<<" ";
	  list<int>::iterator itr;
	  for(itr=g->adj[t].begin();itr!=g->adj[t].end();itr++)
	  {
	  	
	        q.push(make_pair(*itr,b+1));
	  } 		
	}
}
int main()
{
graph *g=create(7);	
addedge(g,0,1);
addedge(g,0,2);
addedge(g,1,3);
addedge(g,1,4);
addedge(g,1,5);
addedge(g,2,6);

bfs(g,3);
}
