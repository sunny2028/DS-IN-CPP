#include<bits/stdc++.h>
using namespace std;
void generate_derangement(int n)
{
	priority_queue<int,vector<int>,greater<int> >p;
	int res[n];
	for(int i=1;i<=n;i++)
	{
		p.push(i);
	}
	for(int i=1;i<=n;i++)
	{
		int t=p.top();
		p.pop();
		if(t!=i||i==n)
		   res[i-1]=t;
		   else
		   {
		   	res[i-1]=p.top();
		   	p.pop();
		   	p.push(t);
		   }
	}
	if(res[n-1]==n)
	{
		res[n-1]=res[n-2];
		res[n-2]=n;
	}
	for(int i=0;i<n;i++)
	cout<<res[i]<<" ";
}
int main()
{
	 generate_derangement(10); 
    return 0; 
}
