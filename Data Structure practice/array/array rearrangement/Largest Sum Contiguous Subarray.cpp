#include<bits/stdc++.h>//https://www.geeksforgeeks.org/?p=576
using namespace std;//time complexity: O(n) auxiliary space:O(1)
int kadanes(int a[],int n)
{int min=0,max=0;
for(int i=0;i<n;i++)
{max=max+a[i];
if(max<0)
{
max=0;

}
if(min<max)
min=max;
}
return min;
}
int main()
{int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
cout<<kadanes(arr,8);
}
