#include<iostream>
using namespace std;
struct tour
{
	int petrol;
	int distance;
};
int findtour(tour arr[],int n)
{
	int start=0;
	int end=1;
	int currsum=arr[start].petrol-arr[start].distance;
	while(start!=end)
	{   
	while(currsum<0&&start!=end)
	{
		currsum=currsum-(arr[start].petrol-arr[start].distance);
		start=(start+1)%n;
		if(start==0)
		return -1;
	}
	currsum=currsum+arr[end].petrol-arr[end].distance;
	end=(end+1)%n;
	}
	return start;
}
int main()
{
	tour arr[]={{6, 4}, {3, 6}, {7, 3}};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<findtour(arr,n);
}
