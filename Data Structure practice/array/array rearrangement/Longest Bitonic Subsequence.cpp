#include<bits/stdc++.h>//timecomplexity:O(n^2)   Auxilary space:O(n)
using namespace std;//https://www.geeksforgeeks.org/dynamic-programming-set-15-longest-bitonic-subsequence/
int LongestBitonicSubsequence(int a[],int n)
{int asc[n],desc[n],res[n];
int count=1,temp;
asc[0]=count;
for(int i=1;i<n;i++)
{count=1;
    temp=0;
for(int j=0;j<i;j++)
    {if(a[j]<=a[i]&&a[j]>=temp)
        {temp=a[j];
         count++;
        }
    }
    asc[i]=count;
}
for(int i=0;i<n;i++)
    cout<<asc[i]<<" ";
cout<<"\n";
count=1;
temp=0;
desc[n-1]=count;
for(int i=n-2;i>=0;i--)
{count=1;
for(int j=n-1;j>i;j--)
{if(a[j]<=a[i]&&a[j]>=temp)
    {temp=a[j];
     count++;
    }
}
desc[i]=count;
}
for(int i=0;i<n;i++)
    cout<<desc[i]<<" ";
cout<<"\n";
for(int i=0;i<n;i++)
{res[i]=asc[i]+desc[i]-1;
}
return(*max_element(res,res+n));
}

int main()
{
int arr[]={1, 11, 2, 10, 4, 5, 2, 1};
int l=LongestBitonicSubsequence(arr,8);
cout<<l;


}
