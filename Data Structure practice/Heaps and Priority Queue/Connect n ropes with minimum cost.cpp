#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int minCost(int *arr,int n)
{
	priority_queue<int,vector<int>,greater<int> >p(arr,arr+n);
	int sum=0;
	while(!p.empty())
	{
		int a=p.top();
		p.pop();
		if(p.empty())
		break;
		int b=p.top();
		p.pop();
		p.push(a+b);
		sum+=a+b;		
	}
	return sum;
}
int main() 
{ 
    int len[] = {4, 3, 2, 6}; 
    int size = sizeof(len)/sizeof(len[0]); 
    cout << "Total cost for connecting ropes is " << minCost(len, size); 
    return 0; 
}
