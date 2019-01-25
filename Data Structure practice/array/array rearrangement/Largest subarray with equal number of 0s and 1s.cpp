#include<bits/stdc++.h>
using namespace std;
void findsubarray(int a[],int n)
{int sum,j,start,maxlength=-1;
for(int i=0;i<n;i++)
{if(a[i]==0)
sum=-1;
else
sum=1;
for(j=i+1;j<n;j++)
{if(a[j]==0)
sum-=1;
else
sum+=1;
if(sum==0&&maxlength<j-i+1)
{maxlength=j-i+1;
start=i;
}
}
}
cout<<start<<"    "<<start+maxlength-1;
}

int main()
{int arr[]={1, 0, 0, 1, 0, 1, 1};
findsubarray(arr,7);
}
