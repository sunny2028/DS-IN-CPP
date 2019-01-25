#include<bits/stdc++.h>
using namespace std;
bool visited(vector<int>p,int a)
{
	for(int i=0;i<p.size();i++)
	{
		if(p[i]==a)
		return true;
	}
	return false;
}
void printpath(vector<int>v)
{
	for(int i=0;i<v.size();i++)
	  cout<<v[i]<<" ";
	  cout<<'\n';
}
void findpaths(vector<vector<int> >g,int s,int d,int n)
{
	queue<vector<int> >q;
	vector<int>path;
	path.push_back(s);
	q.push(path);
	while(!q.empty())
	{ 
		vector<int>p=q.front();
		q.pop();
		int last=p[p.size()-1];
		if(last==d)
		{
			printpath(p);
		}
		else
		{
			for(int i=0;i<g[last].size();i++)
			{if(!visited(p,g[last][i]))
			{
			vector<int>newpath(p);
			newpath.push_back(g[last][i]);
			q.push(newpath);
		    }
			}
	    }
	}
}

int main() 
{ 
    vector<vector<int> > g; 
    // number of vertices 
    int v = 4; 
    g.resize(4); 
  
    // construct a graph 
    g[0].push_back(3); 
    g[0].push_back(1); 
    g[0].push_back(2); 
    g[1].push_back(3); 
    g[2].push_back(0); 
    g[2].push_back(1); 
  
    int src = 2, dst = 3; 
    cout << "path from src " << src 
         << " to dst " << dst << " are \n"; 
  
    // function for finding the paths 
    findpaths(g, src, dst, v); 
  
    return 0; 
} 
