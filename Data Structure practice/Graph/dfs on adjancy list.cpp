#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
struct adjlist
{
	Node *head;
};
struct graph
{
	int v;
	int u;
	adjlist* h;
};
graph* adjancylist()
{  int x,y;
	graph* g=new graph;
	cin>>g->u>>g->v;
	g->h=new adjlist[g->v];
	for(int i=0;i<g->v;i++)
	{   
		g->h[i].head = NULL;
	}
	for(int i=0;i<g->u;i++)
	{
		cin>>x>>y;
		Node* temp=new Node;
		temp->data=y;
		temp->next=g->h[x].head;
		g->h[x].head=temp;
	}
	return g;
}
void dfsutil(int *visited,graph *g,int i)
{
	visited[i]=1;
	cout<<i;
	Node* hh=g->h[i].head;
	while(hh)
	{
		if(!visited[hh->data])
		      dfsutil(visited,g,hh->data);
		      
		      hh=hh->next;
	}
}
void dfs(graph *g)
{
	int visited[g->v];
	memset(visited,0,g->v*sizeof(int));
	for(int i=0;i<g->v;i++)
	{
		if(!visited[i])
		dfsutil(visited,g,i);
	}
}
int main()
{
	graph* g=adjancylist();
	dfs(g);
}
