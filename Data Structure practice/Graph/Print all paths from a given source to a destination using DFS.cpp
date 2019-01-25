// C++ program to print all paths from a source to destination. 
#include<bits/stdc++.h>
using namespace std; 

// A directed graph using adjacency list representation 
class Graph 
{ 
	int V; // No. of vertices in graph 
	list<int> *adj; // Pointer to an array containing adjacency lists 

	// A recursive function used by printAllPaths() 
	void printAllPathsUtil(int , int , bool [], int [], int &); 

public: 
	Graph(int V); // Constructor 
	void addEdge(int u, int v); 
	void printAllPaths(int s, int d); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int u, int v) 
{ 
	adj[u].push_back(v); // Add v to u’s list. 
} 

// Prints all paths from 's' to 'd' 
void Graph::printAllPaths(int s, int d) 
{ 
bool visited[V];
memset(visited,false,sizeof(visited));
int path[V];
int pathindex=0;
printAllPathsUtil(s,d,visited,path,pathindex);
}
void Graph::printAllPathsUtil(int s,int d,bool *visited,int *path,int &pathindex)
{
	visited[s]=true;
	path[pathindex]=s;
	pathindex++;
	if(s==d)
	{
		for(int i=0;i<pathindex;i++)
		     cout<<path[i]<<" ";
		     cout<<'\n';
	}
	else
	{
		list<int>::iterator itr;
		for(itr=adj[s].begin();itr!=adj[s].end();itr++)
		{
			if(!visited[*itr])
			{
				printAllPathsUtil(*itr,d,visited,path,pathindex);
			}
		}
	}
	pathindex--;
	visited[s]=false;
}
// Driver program 
int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(0, 3); 
	g.addEdge(2, 0); 
	g.addEdge(2, 1); 
	g.addEdge(1, 3); 

	int s = 2, d = 3; 
	cout << "Following are all different paths from " << s 
		<< " to " << d << endl; 
	g.printAllPaths(s, d); 

	return 0; 
} 

