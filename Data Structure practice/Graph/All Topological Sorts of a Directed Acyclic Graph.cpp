// C++ program to print all topological sorts of a graph 
#include <bits/stdc++.h> 
using namespace std; 

class Graph 
{ 
	int V; // No. of vertices 

	// Pointer to an array containing adjacency list 
	list<int> *adj; 

	// Vector to store indegree of vertices 
	vector<int> indegree; 

	// A function used by alltopologicalSort 
	void alltopologicalSortUtil(vector<int>& res, 
								bool visited[]); 

public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// Prints all Topological Sorts 
	void alltopologicalSort(); 
}; 

// Constructor of graph 
Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 

	// Initialising all indegree with 0 
	for (int i = 0; i < V; i++) 
		indegree.push_back(0); 
} 

// Utility function to add edge 
void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v's list. 

	// increasing inner degree of w by 1 
	indegree[w]++; 
} 

// Main recursive function to print all possible 
// topological sorts 
void Graph::alltopologicalSortUtil(vector<int>& res, 
								bool visited[]) 
{ 
	int flag=0;
	for(int i=0;i<V;i++)
	{
		if(indegree[i]==0&&!visited[i])
		{
			list<int>::iterator itr;
			for(itr=adj[i].begin();itr!=adj[i].end();itr++)
			{
				indegree[*itr]--;
			}
			visited[i]=true;
			res.push_back(i);
			alltopologicalSortUtil(res,visited);
			visited[i]=false;
			res.erase(res.end()-1);
			for(itr=adj[i].begin();itr!=adj[i].end();itr++)
			{
				indegree[*itr]++;
			}
			flag=1;
		}
	}
	if(!flag)
	{
		for(int i=0;i<res.size();i++)
		   cout<<res[i]<<" ";
		   cout<<"\n";
	}
} 

// The function does all Topological Sort. 
// It uses recursive alltopologicalSortUtil() 
void Graph::alltopologicalSort() 
{
bool visited[V];
memset(visited,false,sizeof(visited));
vector<int>res;
alltopologicalSortUtil(res,visited);
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

	cout << "All Topological sorts\n"; 

	g.alltopologicalSort(); 

	return 0; 
} 
