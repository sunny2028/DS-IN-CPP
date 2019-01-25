#include<bits/stdc++.h>//time complexity:O(n)
using namespace std;//https://www.geeksforgeeks.org/sort-array-wave-form-2/
void waveform(int a[],int n)
{
for(int i=0;i<n;i+=2)
{if(i>0&&a[i]<a[i-1])
 swap(a[i],a[i-1]);
 if(i<n-1&&a[i]<a[i+1])
  swap(a[i],a[i+1]);
}

}

int main()
{
int arr[]={10, 5, 6, 2, 20, 3, 100, 80};
waveform(arr,8);
for(int i=0;i<8;i++)
cout<<arr[i]<<" ";
return 0;
}
