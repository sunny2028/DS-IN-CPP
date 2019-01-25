#include<iostream>
using namespace std;
void query1(int *torotate,int k,int n)
{
	*torotate=(*torotate-k)%n;
}
void query2(int *torotate,int k,int n)
{
	*torotate=(*torotate+n+k)%n;
}
void query3(int torotate,int a,int b,int *temp,int n)
{
	 a=(a+torotate+n)%n;
	 b=(b+torotate+n)%n;
	if(a<b)
	{
		cout<<temp[b+1]-temp[a];
	}
	else
	   cout<<temp[n]+temp[b+1]-temp[a];
}
void apply(int *arr,int n)
{
	int temp[n+1];
	temp[0]=0;
	for(int i=1;i<=n;i++)
	{
		temp[i]=arr[i-1]+temp[i-1];
	}
	int torotate=0;
	query1(&torotate,3,n);
	query2(&torotate,1,n);
	query3(torotate,1,4,temp,n);
}
int main()
{
	int arr[]={1,2,3,4,5};
	apply(arr,5);
	
}
