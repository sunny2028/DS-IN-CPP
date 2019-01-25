#include<bits/stdc++.h>//time complexity O(n)  auxiliary space:O(1)
using namespace std;
void seggregate(int a[],int n)
{int left=0,right=n-1;
while(left<right)
{while(left<right&&a[left]==0)
left++;
while(left<right&&a[right]==1)
 right--;
 if(left<right)
 {a[left]=0;
 a[right]=1;
 left++;
 right--;
 }
}
}
int main()
{int arr[]={0,1,1,0,1,0,0,1};
seggregate(arr,8);
for(int i=0;i<8;i++)
cout<<arr[i]<<" ";
}
