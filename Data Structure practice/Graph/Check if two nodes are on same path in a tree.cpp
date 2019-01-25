#include<bits/stdc++.h>
using namespace std;
#define MAX 10
int timer=0;
bool visited[MAX]={false};
int intime[MAX];
int outtime[MAX];
void dfs(vector<int>*v,int n)
{
	visited[n]=true;
	timer++;
	intime[n]=timer;
	for(int i=0;i<v[n].size();i++)
	{
		if(!visited[v[n][i]])
		{
			dfs(v,v[n][i]);
		}
	}
	timer++;
	outtime[n]=timer;
}
bool query(int a,int b)
{
	return (intime[a]<intime[b]&&outtime[a]>outtime[b]||intime[a]>intime[b]&&outtime[a]<outtime[b]);
}
int main() 
{ 
    // Let us create above shown tree 
    int n = 9; // total number of nodes 
    vector<int> graph[n+1]; 
    graph[1].push_back(2); 
    graph[1].push_back(3); 
    graph[3].push_back(6); 
    graph[2].push_back(4); 
    graph[2].push_back(5); 
    graph[5].push_back(7); 
    graph[5].push_back(8); 
    graph[5].push_back(9); 
    dfs(graph,1);
    query(1, 5)? cout << "Yes\n" : cout << "No\n"; 
    query(2, 9)? cout << "Yes\n" : cout << "No\n"; 
    query(2, 6)? cout << "Yes\n" : cout << "No\n"; 
  
    return 0;   
}
