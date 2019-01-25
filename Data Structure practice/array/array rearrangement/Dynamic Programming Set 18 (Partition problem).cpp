#include<bits/stdc++.h>
using namespace std;
bool check(int a[],int n,int sum)
{if(sum==0)
return true;
if(n==0&&sum!=0)
return false;
if(a[n-1]>sum)
return check(a,n-1,sum);
else
return check(a,n-1,sum)||check(a,n-1,sum-a[n-1]);
}
bool partition(int a[],int n)
{int sum=accumulate(a,a+n,0);
if(sum%2!=0)
return false;
return check(a,n,sum/2);

}
int main()
{int arr[]={1,11,5,5};
cout<<partition(arr,4);
}
