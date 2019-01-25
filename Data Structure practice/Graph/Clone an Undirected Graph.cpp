#include<bits/stdc++.h>
using namespace std;
struct Graph
{
	int val;
	vector<Graph*> v;
};
Graph* buildGraph()
{
	Graph *node1=new Graph;
	node1->val=1;
	Graph* node2=new Graph;
	node2->val=2;
		Graph* node3=new Graph;
	node3->val=3;
		Graph* node4=new Graph;
	node4->val=4;
	vector<Graph*> v;
	v.push_back(node2);
	v.push_back(node4);
	node1->v=v;
	v.clear();
	v.push_back(node1);
	v.push_back(node3);
	node2->v=v;
	v.clear();
	v.push_back(node2);
	v.push_back(node4);
	node3->v=v;
	v.clear();
	v.push_back(node1);
	v.push_back(node3);
	node4->v=v;
	v.clear();
	return node1;
}
void bfs(Graph* g)
{    map<Graph*,bool>visited;
	queue<Graph*>q;
	q.push(g);
	visited[g]=true;
	while(!q.empty())
	{
		Graph* a=q.front();
		q.pop();
	
		cout<< a->val<<"    "<<a<<"\n";
		vector<Graph*> v=a->v;
		for(int i=0;i<v.size();i++)
		{ 
		if(!visited[v[i]])
		{
		visited[v[i]]=true;
		q.push(v[i]);	
		}	
		}
	}
}
Graph* clonegraph(Graph* g)
{  map<Graph*,Graph*>m;
  queue<Graph*>q;
  q.push(g);
	Graph* n=new Graph();
	n->val=g->val;
	m[g]=n;
	while(!q.empty())
	{
		Graph* g=q.front();
		q.pop();
		vector<Graph* >v=g->v;
		for(int i=0;i<v.size();i++)
		{
			if(m[v[i]]==NULL)
			{
				Graph* j=new Graph();
				j->val=v[i]->val;
				m[v[i]]=j;
				q.push(v[i]); 
			}
			m[g]->v.push_back(m[v[i]]);
		}
	}
	return m[g];
 
}
int main()
{
	Graph *g=buildGraph();
	cout<<"original\n";
	bfs(g);
	Graph* n=clonegraph(g);
	cout<<"\ncloned\n";
	bfs(n);
}
