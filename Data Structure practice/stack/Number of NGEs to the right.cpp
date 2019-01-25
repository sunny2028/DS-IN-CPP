#include<bits/stdc++.h>
using namespace std;
void convert1(int arr[],int next[],int n)
{
	stack<int>s;
	s.push(0);
	for(int i=1;i<n;i++)
	{
		while(!s.empty()&&arr[i]>arr[s.top()])
		{
			next[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty())
	{
		next[s.top()]=-1;
		s.pop();
	}
}
void convert(int arr[],int dp[],int n)
{
	int next[n];
	convert1(arr,next,n);
	for(int i=n-2;i>=0;i--)
	{    if(next[i]==-1)
	       dp[i]=0;
	       else
		   		dp[i]=1+dp[next[i]];
	}
}
int count(int dp[],int index)
{
	return dp[index];
}
int main()
{
	int arr[]={1,2,3,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	int dp[n]={0};
	convert(arr,dp,n);
	cout<<count(dp,0)<<"\n";
	cout<<count(dp,3);
	
}
