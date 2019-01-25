#include<bits/stdc++.h>
using namespace std;
bool hasOnlyOneChild(int *arr,int n)
{
	int min=INT_MIN;
	int max=INT_MAX;
	for(int i=1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
		max=arr[i-1];
		else
		min=arr[i-1];
		if(arr[i]<min||arr[i]>max)
		return false;
	}
	return true;
}
// Driver program to test above function 
int main() 
{ 
    int pre[] = {10,5,30,50,65}; 
    int size = sizeof(pre)/sizeof(pre[0]); 
    if (hasOnlyOneChild(pre,size)) 
        printf("Yes"); 
    else
        printf("No"); 
    return 0; 
} 

