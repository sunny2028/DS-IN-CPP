#include<bits/stdc++.h>
using namespace std;//https://www.geeksforgeeks.org/maximum-length-bitonic-subarray/
int bitonic(int a[],int n)
{int inc[n],dec[n],res[n],index;
int count=1,i;
inc[0]=count;
for(i=0;i<n-1;i++)
{if(a[i]<a[i+1])
count++;
else
count=1;
inc[i+1]=count;
}
count=1;
dec[n-1]=count;
for(i=n-2;i>=0;i--)
{if(a[i+1]<a[i])
count++;
else
count=1;
dec[i]=count;
}
for(i=0;i<n;i++)
res[i]=inc[i]+dec[i]-1;
int max=0;
for(i=0;i<n;i++)
{if(res[i]>max)
  {
  max=res[i];
  index=i;
  }
}
int start=index-inc[index]+1;
int end=index+dec[index]-1;
for(i=start;i<=end;i++)
    cout<<a[i]<<" ";
    cout<<"\n";
return(*max_element(res,res+n));
}
int main()
{int arr[]={12, 4, 78, 90, 45, 23};
int l=bitonic(arr,6);
cout<<l;






}
