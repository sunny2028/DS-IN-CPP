#include<bits/stdc++.h>
using namespace std;//https://www.geeksforgeeks.org/maximum-length-bitonic-subarray-set-2-time-o1-space/
int bitonic(int a[],int n)//TIME COMPLEXITY :O(n)  //AUXILIARY space:O(1)
{int start=0;
int j=0;
int next_start=0;
int maxlength=1;
if(n==0)
return 0;
while(j<n-1)
{while(j<n-1&&a[j]<a[j+1])
j++;
while(j<n-1&&a[j]>=a[j+1])
{if(j<n-1&&a[j]>a[j+1])
   next_start=j+1;
   j++;
}
maxlength=max(maxlength,j-start+1);
start=next_start;
}
return maxlength;
}

int main()
{int arr[]={12, 4, 78, 90, 45, 23};
cout<<bitonic(arr,6);

}
