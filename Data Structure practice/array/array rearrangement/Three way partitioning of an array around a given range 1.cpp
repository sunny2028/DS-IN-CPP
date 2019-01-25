#include<bits/stdc++.h>
using namespace std;
void check(int a[],int n,int low,int high)
{int start=0;
int end=n-1;
for(int i=0;i<=end;)
{if(a[i]<low)
swap(a[i++],a[start++]);
else if(a[i]>high)
swap(a[i],a[end--]);
else
i++;
}
}
int main()
{int arr[]={1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
int low=14,high=20;
check(arr,13,low,high);
for(int i=0;i<13;i++)
cout<<arr[i]<<" ";

}
