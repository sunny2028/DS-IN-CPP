#include<bits/stdc++.h>
using namespace std;
int findmaxhamming(int *arr,int n)
{
	int arr1[2*n],count,maximum=0,k;
	for(int i=0;i<n;i++)
	{
		arr1[i]=arr1[i+n]=arr[i];
	}
	for(int i=1;i<n;i++)
	{  count=0;
		for(int j=i,k=0;j<i+n;j++,k++)
		{
			if(arr1[j]!=arr[k])
			count++;
			if(count==n)
			return n;
			maximum=max(count,maximum);
		}
	}
	return maximum;
}
int main()
{
	int arr[]={1,4,1};
	cout<<findmaxhamming(arr,3);
}
