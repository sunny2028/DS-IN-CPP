#include<bits/stdc++.h>
using namespace std;
void windowmaximum(int arr[],int n,int k)
{
	deque<int>q(k);
	int i;
	for(i=0;i<k;i++)
	{
		while(!q.empty()&&arr[i]>arr[q.back()])
		q.pop_back();
		
		q.push_back(i);
	}
	for(;i<n;i++)
	{
		cout<<arr[q.front()]<<" ";
		while(!q.empty()&&q.front()<=i-k)
		q.pop_front();
		while(!q.empty()&&arr[i]>arr[q.back()])
		q.pop_back();
		q.push_back(i);
	}
	cout<<arr[q.front()];
}
int main()
{
	int arr[]={1, 2, 3, 1, 4, 5, 2, 3, 6};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	windowmaximum(arr,n,k);
}
