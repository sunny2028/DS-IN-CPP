#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> *adj,int* color,int n,int c)
{
	color[c]++;
	for(int i=0;i<adj[n].size();i++)
	{
		dfs(adj,color,adj[n][i],!c);
	}
	
}
int findMaxEdges(vector<int> *adj,int n)
{
	int color[2];
	color[0]=color[1]=0;
	dfs(adj,color,1,0);
	return color[0]*color[1]-(n-1);
}
int main() 
{ 
    int n = 5; 
    vector<int> adj[n + 1]; 
    adj[1].push_back(2); 
    adj[1].push_back(3); 
    adj[2].push_back(4); 
    adj[3].push_back(5); 
    cout << findMaxEdges(adj, n); 
    return 0; 
} 
