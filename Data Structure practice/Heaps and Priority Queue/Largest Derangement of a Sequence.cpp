#include<bits/stdc++.h>
using namespace std;
void printLargest(int *seq,int n)
{
	priority_queue<int>p;
	int res[n];
	for(int i=0;i<n;i++)
	{
		p.push(seq[i]);
	}
	for(int i=0;i<n;i++)
	{
		int t=p.top();
		p.pop();
		if(t!=seq[i]||i==n-1)
		res[i]=t;
		else
		{
			res[i]=p.top();
			p.pop();
			p.push(t);
		}
	}
	if(res[n-1]==seq[n-1])
      {
      	res[n-1]=res[n-2];
      	res[n-2]=seq[n-1];
	  }
	  for(int i=0;i<n;i++)
	  cout<<res[i]<<" ";
  }
int main() 
{ 
    int seq[] = { 92, 3, 52, 13, 2, 31, 1 };  
    int n = sizeof(seq)/sizeof(seq[0]); 
    printLargest(seq, n); 
    return 0; 
} 
