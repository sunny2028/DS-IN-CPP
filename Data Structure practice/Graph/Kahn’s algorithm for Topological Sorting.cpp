// A C++ program to print topological sorting of a graph 
// using indegrees. 
#include<bits/stdc++.h> 
using namespace std; 

// Class to represent a graph 
class Graph 
{ 
	int V; // No. of vertices' 

	// Pointer to an array containing adjacency listsList 
	list<int> *adj; 

public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int u, int v); 

	// prints a Topological Sort of the complete graph 
	void topologicalSort(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int u, int v) 
{ 
	adj[u].push_back(v); 
} 

// The function to do Topological Sort. 
void Graph::topologicalSort() 
{ 
	vector<int>indegree(V,0);
	vector<int>res;
	int count=0;
	for(int i=0;i<V;i++)
	{
		list<int>::iterator itr;
		for(itr=adj[i].begin();itr!=adj[i].end();itr++)
		{
			indegree[*itr]++;
		}
	}
	queue<int>q;
	for(int i=0;i<V;i++)
	{
		if(indegree[i]==0)
		q.push(i);
	}
	while(!q.empty())
	{
		int a=q.front();
		q.pop();
		res.push_back(a);
		count++;
		list<int>::iterator itr;
		for(itr=adj[a].begin();itr!=adj[a].end();itr++)
		{
			if(--indegree[*itr]==0)
			q.push(*itr);
		}
		
	}
	if(count!=V)
	cout<<"Topological sort not possibe";
	else
	{
		for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	}
		
}
	
// Driver program to test above functions 
int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(6); 
	g.addEdge(5, 2); 
	g.addEdge(5, 0); 
	g.addEdge(4, 0); 
	g.addEdge(4, 1); 
	g.addEdge(2, 3); 
	g.addEdge(3, 1); 

	cout << "Following is a Topological Sort of\n"; 
	g.topologicalSort(); 

	return 0; 
} 

