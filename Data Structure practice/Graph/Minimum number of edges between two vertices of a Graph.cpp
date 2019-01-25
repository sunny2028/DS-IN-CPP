#include<bits/stdc++.h>
using namespace std;
void addEdge(vector <int> edges[], int u, int v) 
{ 
   edges[u].push_back(v); 
   edges[v].push_back(u); 
} 
  
  int minEdgeBFS(vector<int> *edges,int s,int d,int n)
  { bool visited[n];
    memset(visited,false,sizeof(visited));
  	queue<int>q;
  	q.push(s);
  	q.push(INT_MAX);
  	visited[s]=true;
  	int count=0;
  	while(!q.empty())
  	{
  	int a=q.front();
	  q.pop();
	  if(a==INT_MAX)
	    {
		count++;
		q.push(INT_MAX);
	    }
	  else if(a==d)
	      break;
		  else
		  {
		  for(int i=0;i<edges[a].size();i++)
		  {
		  if(!visited[edges[a][i]])	
		  {
		  	visited[edges[a][i]]=true;
		  	q.push(edges[a][i]);
		  }
		  }	
		  
		  }	
	}
	return count;
  }
// Driver function 
int main() 
{ 
    // To store adjacency list of graph 
    int n = 9; 
    vector <int> edges[9]; 
    addEdge(edges, 0, 1); 
    addEdge(edges, 0, 7); 
    addEdge(edges, 1, 7); 
    addEdge(edges, 1, 2); 
    addEdge(edges, 2, 3); 
    addEdge(edges, 2, 5); 
    addEdge(edges, 2, 8); 
    addEdge(edges, 3, 4); 
    addEdge(edges, 3, 5); 
    addEdge(edges, 4, 5); 
    addEdge(edges, 5, 6); 
    addEdge(edges, 6, 7); 
    addEdge(edges, 7, 8); 
    int u = 0; 
    int v = 5; 
    cout << minEdgeBFS(edges, u, v, n); 
    return 0; 
} 
