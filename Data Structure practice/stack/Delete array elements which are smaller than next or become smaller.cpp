#include<bits/stdc++.h>
using namespace std;

void deleteElements(int *arr,int n,int k)
{ stack<int>s;
int count=0;
	for(int i=0;i<n;i++)
	{
		if(s.empty()||arr[i]<=s.top())
             s.push(arr[i]);
             else
             {
             	while(!s.empty()&&count<k)
             	{
             	s.pop();
				count++;	
				}
				s.push(arr[i]);
			 }
	}
	vector<int>v(s.size());
	for(int i=s.size()-1;i>=0;i--)
	{
	v[i]=s.top();
	s.pop();
    }
   for(int j=0;j<v.size();j++)
   cout<<v[j]<<" ";
}
int main()
{
	 int n = 5, k = 3;
    int arr[] = {20, 10, 25, 30, 40}; 
    deleteElements(arr, n, k);
    return 0;
}
