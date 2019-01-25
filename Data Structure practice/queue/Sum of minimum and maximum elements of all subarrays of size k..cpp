#include<bits/stdc++.h>
using namespace std;
int countsum(int arr[],int n,int k)
{deque<int>s(k);
deque<int>g(k);
int i;
int sum=0;
for(i=0;i<k;i++)
{
	while(!g.empty()&&arr[i]>arr[g.back()])
	g.pop_back();
	g.push_back(i);
	
while(!s.empty()&&arr[i]<arr[s.back()])
  s.pop_back();
  s.push_back(i);
}
for(;i<n;i++)
{
	sum=sum+arr[s.front()]+arr[g.front()];
	while(!g.empty()&&g.front()<=i-k)
	g.pop_front();
	while(!g.empty()&&arr[i]>arr[g.back()])
	g.pop_back();
	g.push_back(i);
	while(!s.empty()&&s.front()<=i-k)
	s.pop_front();
	while(!s.empty()&&arr[i]<arr[s.back()])
	s.pop_back();
	s.push_back(i);
}
sum=sum+arr[s.front()]+arr[g.front()];
return sum;
	
}
int main()
{
	int arr[]={2, 5, -1, 7, -3, -1, -2};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	cout<<countsum(arr,n,k);
	return 0;
}
