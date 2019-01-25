#include<bits/stdc++.h>
using namespace std;
struct compare
{
	bool operator()(pair<int,int>&p1,pair<int,int>&p2)
	{
		if(p1.second==p2.second)
		return p1.first<p2.first;
		
		return p1.second<p2.second;
	}
};
void print_N_mostFrequentNumber(int *arr,int n,int k)
{
	map<int,int>m;
	for(int i=0;i<n;i++)
	m[arr[i]]++;
	priority_queue<pair<int,int>,vector<pair<int,int> >,compare>p(m.begin(),m.end());
	while(k--)
	{
		cout<<p.top().first;
		p.pop();
	}
}
int main() 
{ 
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 2; 
    print_N_mostFrequentNumber(arr, n, k); 
    return 0; 
}
