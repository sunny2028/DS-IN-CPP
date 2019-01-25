#include<bits/stdc++.h>
using namespace std; 
  
class Graph 
{ int V;
list<int> *l;
bool *visited;
public: Graph(int v)
{
	V=v;
	l=new list<int>[v];
	visited=new bool[v];
	memset(visited,false,sizeof(visited));
}
void addEdge(int u,int v)
{
	l[u].push_back(v);
	l[v].push_back(u);
}
bool detectcycle();
void dfs(int a,bool &flag);
};
bool Graph::detectcycle()
{  bool flag=true;
	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{
	   		dfs(i,flag);
	   		if(flag==false)
		return true;
		}
	
	}
	return false;
}
void Graph::dfs(int j,bool &flag)
{
	visited[j]=true;
	list<int>::iterator itr;
	for( itr=l[j].begin();itr!=l[j].end();itr++)
	{  
		if(!visited[*itr])
		    dfs(*itr,flag);
		else 
		flag=false;
	}
}
int main()
{
	Graph *g=new Graph(4);
	g->addEdge(0, 1); 
    g->addEdge(0, 2); 
    g->addEdge(1, 2); 
    g->addEdge(2, 0); 
    g->addEdge(2, 3); 
    g->addEdge(3, 3);
	cout<<g->detectcycle(); 
}

