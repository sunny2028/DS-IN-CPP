#include<bits/stdc++.h>
using namespace std;
struct person
{
	int val;
	int occurance;
};
struct check
{
	bool operator()(person& p1,person& p2)
	{
		if(p1.occurance<p2.occurance)
		return true;
		else if(p1.occurance==p2.occurance)
		    return p1.val<p2.val;
		    
		    return false;
	}
	
};
void  print_N_mostFrequentNumber(int *arr,int n,int k)
{
	priority_queue<person,vector<person>,check>p;
	map<int,int>m;
	for(int i=0;i<n;i++)
	{
		m[arr[i]]++;
	}
	map<int,int>::iterator itr;
	for(itr=m.begin();itr!=m.end();itr++)
	{
		person obj;
		obj.val=itr->first;
		obj.occurance=itr->second;
		p.push(obj);
	}
	while(k--)
	{
		person obj=p.top();
		p.pop();
		cout<<obj.val<<"\n";
	}
}
int main() 
{ 
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 6; 
    print_N_mostFrequentNumber(arr, n, k); 
    return 0; 
}
