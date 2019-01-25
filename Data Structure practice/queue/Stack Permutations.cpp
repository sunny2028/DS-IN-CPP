#include<bits/stdc++.h>
using namespace std;
bool check(int arr[],int arr1[],int n)
{   queue<int>q;
stack<int>s;
queue<int>q1;
	for(int i=0;i<n;i++)
	{
		q.push(arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		int j=arr1[i];
		if(s.empty())
		{
			while(!q.empty()&&q.front()!=j)
			{
				s.push(q.front());
				q.pop();
			}
			if(q.empty())
			return false;
				s.push(q.front());
				q.pop();
				q1.push(s.top());
				s.pop();
		}
		else if(arr1[i]==s.top())
		{
				q1.push(s.top());
				s.pop();
		}
		else
		{
			while(!q.empty()&&q.front()!=arr1[i])
			      {
				  s.push(q.front());
				  q.pop();
			      }
			      if(q.empty())
			      return false;
			      q1.push(q.front());
			      q.pop();
		}
	}
	return true;
}
int main()
{
	int arr[]={1,2,3};
	int arr1[]={2,3,1};
	cout<<check(arr,arr1,3);
}
