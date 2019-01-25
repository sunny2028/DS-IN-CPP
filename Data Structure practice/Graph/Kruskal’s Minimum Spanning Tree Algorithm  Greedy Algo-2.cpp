#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int src;
	int dest;
	int weight;
	
};
class Graph
{
  public:int V;
  int E;
  Edge *edge;
    
};
Graph* createGraph(int v,int e)
  	{
  	Graph* g=new Graph;
  	g->V=v;
	g->E=e;
	g->edge=new Edge[e];  	
	}
struct subset
{
	int parent;
	int rank;
};
int mycomp(const void* a,const void* b)
{
	Edge* aa=(Edge*)a;
	Edge* bb=(Edge*)b;
	return aa->weight>bb->weight;
}
int find(subset* s,int i)
{
	if(s[i].parent!=i)
	s[i].parent=find(s,s[i].parent);
	return s[i].parent;
}
void Union(subset* s,int x,int y)
{
	int xx=find(s,x);
	int yy=find(s,y);
	if(s[xx].rank<s[yy].rank)
	s[xx].parent=yy;
	else if(s[xx].rank>s[yy].rank)
	s[yy].parent=xx;
	else
	{
		s[yy].parent=xx;
		s[xx].rank++;
	}
}
void Kruskal(Graph* g)
{
	Edge res[g->V];
	int e=0;
	int i=0;
	subset* s=new subset[g->V];
	qsort(g->edge,g->E,sizeof(g->edge[0]),mycomp);
	for(int i=0;i<g->V;i++)
	{
		s[i].parent=i;
		s[i].rank=0;
	}
   while(e<g->V-1)
	{  Edge nextedge=g->edge[i++];
		int x=find(s,nextedge.src);
		int y=find(s,nextedge.dest);
		if(x!=y)
		{
			res[e++]=nextedge;
			Union(s,x,y);
		}
	}
	for(int j=0;j<e;j++)
	{
		cout<<res[j].src<<"  "<<res[j].dest<<"  "<<res[j].weight<<"\n";
	}
}
int main()
{
	Graph* graph=createGraph(4,5);
	graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = 10; 
  
    // add edge 0-2 
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 6; 
  
    // add edge 0-3 
    graph->edge[2].src = 0; 
    graph->edge[2].dest = 3; 
    graph->edge[2].weight = 5; 
  
    // add edge 1-3 
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 15; 
  
    // add edge 2-3 
    graph->edge[4].src = 2; 
    graph->edge[4].dest = 3; 
    graph->edge[4].weight =4;
    Kruskal(graph);
}
