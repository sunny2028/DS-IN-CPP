#include<bits/stdc++.h>
using namespace std;
int maxDistinctNum(int*arr,int n,int k)
{
map<int,int>m;
for(int i=0;i<n;i++)
m[arr[i]]++;
priority_queue<int>p;
map<int,int>::iterator itr;
for(itr=m.begin();itr!=m.end();itr++)
{
p.push(itr->second);
}
while(k--)
{
int t=p.top();
p.pop();
t--;
if(t!=0)
p.push(t);	
}
int count=0;
while(!p.empty())
{
	int t=p.top();
	p.pop();
	if(t==1)
	count++;
}
return count;
}
int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 6; 
    cout << "Maximum distinct elements = "
         << maxDistinctNum(arr, n, k); 
    return 0; 
} 
