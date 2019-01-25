// C++ Program to check if there is a negative weight 
// cycle using Floyd Warshall Algorithm 
#include<iostream> 
using namespace std; 

// Number of vertices in the graph 
#define V 4 

/* Define Infinite as a large enough value. This 
value will be used for vertices not connected 
to each other */
#define INF 99999 

// A function to print the solution matrix 
void printSolution(int dist[][V]); 

// Returns true if graph has negative weight cycle 
// else false. 
bool negCyclefloydWarshall(int graph[][V]) 
{ 
	int dist[V][V];
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			dist[i][j]=graph[i][j];
		}
	}
	for(int k=0;k<V;k++)
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				   dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	for(int i=0;i<V;i++)
	{
		if(dist[i][i]<0)
		  return true;
	}
	return false;
}

// driver program 
int main() 
{ 
	/* Let us create the following weighted graph 
			1 
	(0)----------->(1) 
	/|\			 | 
	|			 | 
-1 |			 | -1 
	|			 \|/ 
	(3)<-----------(2) 
		-1	 */
		
	int graph[V][V] = { {0 , 1 , INF , INF}, 
						{INF , 0 , -1 , INF}, 
						{INF , INF , 0 , -1}, 
						{-1 , INF , INF , 0}}; 
	
	if (negCyclefloydWarshall(graph)) 
	cout << "Yes"; 
	else
	cout << "No"; 
	return 0; 
} 

