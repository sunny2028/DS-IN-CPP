#include<bits/stdc++.h>
using namespace std;
int findmax(int *a,int n)
{ int currsum=0,multi=0;
	for(int i=0;i<n;i++)
	{
		currsum=currsum+a[i];
		multi=multi+i*a[i];
	}
	int maxi=multi;
	for(int i=1;i<n;i++)
	{
		multi=multi+currsum-n*a[n-i];
		maxi=max(maxi,multi);
	}
	return maxi;
}
int main()
{
	int arr[]={10,1,2,3,4,5,6,7,8,9};
	cout<<findmax(arr,10);
}
