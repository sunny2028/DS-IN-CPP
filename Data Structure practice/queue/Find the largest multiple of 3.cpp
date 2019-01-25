#include<bits/stdc++.h>
using namespace std;
int findmax(int arr[],int n)
{  int num=0;
    int flag=0;
	sort(arr,arr+n);
	queue<int>q;
	int sum=accumulate(arr,arr+n,0);
	for(int i=0;i<n;i++)
	{
		q.push(arr[i]);
	}
		int j=0;
	if(sum%3==0)
	{ 
	while(!q.empty())
	{
		num=q.front()*pow(10,j)+num;
		q.pop();
		j++;
    }
	}
	else
	{
		while(!q.empty())
		{
			if((sum-q.front())%3==0&&flag==0)
			{
				flag=1;
			}
			else
			{
				num=q.front()*pow(10,j)+num;
		        j++;
		    }
		    q.pop();
		}
		
	}
	return num;
	
}
int main()
{
	int arr[]={5, 4,4,3,2, 1, 1};
	cout<<findmax(arr,7);
}
