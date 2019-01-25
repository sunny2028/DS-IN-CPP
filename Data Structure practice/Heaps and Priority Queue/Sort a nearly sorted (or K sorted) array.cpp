#include<bits/stdc++.h>
using namespace std;
void sortK(int* arr,int n,int k)
{
	priority_queue<int,vector<int>,greater<int> >p(arr,arr+k+1);
	int index=0;
	for(int i=k+1;i<n;i++)
	{
		arr[index++]=p.top();
		p.pop();
		p.push(arr[i]);
	}
	while(!p.empty())
	{
		arr[index++]=p.top();
		p.pop();
	}
}
void printArray(int *arr,int n)
{
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
}
int main() 
{ 
    int k = 3; 
    int arr[] = { 2, 6, 3, 12, 56, 8 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    sortK(arr, n, k); 
   
    cout << "Following is sorted array\n"; 
    printArray(arr,n); 
   
    return 0; 
}
