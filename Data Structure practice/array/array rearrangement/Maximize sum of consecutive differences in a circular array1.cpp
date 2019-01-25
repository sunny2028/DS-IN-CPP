#include<bits/stdc++.h>//https://www.geeksforgeeks.org/maximize-sum-consecutive-differences-circular-array/
using namespace std;//time complexity:O(nlogn)     auxilary space:O(1)
void maximizecircular(int arr[],int n)
{int sum=0;
sort(arr,arr+n);
for(int i=0;i<n/2;i++)
{sum=sum-2*arr[i];
sum=sum+2*arr[n-i-1];
}
cout<<sum;
}
int main()
{int a[]={ 4, 2, 1, 8 };
maximizecircular(a,4);
}
