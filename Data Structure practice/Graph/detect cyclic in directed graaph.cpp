#include<bits/stdc++.h>
using namespace std; 

class Graph 
{ 
	int V; // No. of vertices 
	    list<int> *l; // Pointer to an array containing adjacency lists 
	bool isCyclicUtil(int v, bool visited[], bool *rs); // used by isCyclic()  
public:

	Graph(int V); // Constructor 
	void addEdge(int v, int w); // to add an edge to graph 
	bool isCyclic(); // returns true if there is a cycle in this graph 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	l = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	l[v].push_back(w); // Add w to v’s list. 
} 

// This function is a variation of DFSUytil() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
if(visited[v]==false)
{
visited[v]=true;
recStack[v]=true;
list<int>::iterator itr;
for(itr=l[v].begin();itr!=l[v].end();itr++)
{
if(!visited[*itr]&&isCyclicUtil(*itr,visited,recStack))
{
return true;	
}	
else if(recStack[*itr])
return true;
}
}	
recStack[v]=false;
return false;

} 

// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclic() 
{ 
	bool* visited=new bool[V];
	bool* rec=new bool[V];
	for(int i=0;i<V;i++)
	visited[i]=rec[i]=false;
	for(int i=0;i<V;i++)
	{
		if(isCyclicUtil(i,visited,rec))
		return true;
	}
	return false;
} 

int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	if(g.isCyclic()) 
		cout << "Graph contains cycle"; 
	else
		cout << "Graph doesn't contain cycle"; 
	return 0; 
} 

