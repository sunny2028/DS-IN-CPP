#include<bits/stdc++.h>
using namespace std;
#define V 4
bool isBipartite(int G[][V],int n)
{ 
	int color[V];
	//int visited[V];
	memset(color,-1,V*sizeof(int));
	//memset(visited,0,V*sizeof(int));
	queue<int>q;
	q.push(n);
	color[n]=1;
	//visited[n]=1;
	while(!q.empty())
	{int a=q.front();
     q.pop();
	for(int i=0;i<V;i++)
	{
		if(a==i&&G[a][i])
		return false;
	if(G[a][i])
	{if(color[i]==color[a])
		return false;
		if(color[i]==-1)
		{
//	visited[i]=1;
	q.push(i);	
	color[i]=!color[a];
        }
	}	
	}	
	}
	return true;
}
int main() 
{ 
    int G[][V] = {{0, 1, 0, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    }; 
  
    isBipartite(G, 0) ? cout << "Yes" : cout << "No"; 
    return 0; 
} 
