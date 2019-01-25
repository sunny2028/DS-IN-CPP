#include<iostream>//https://www.geeksforgeeks.org/replace-every-element-with-the-greatest-on-right-side/
using namespace std;//TIME COMPLEXITY:O(n)  auxiliary space:O(1)
void replacelarge(int a[],int n)
{int temp=a[n-1];
int temp1;
a[n-1]=-1;
for(int i=n-1;i>0;i--)
{if(a[i-1]>=temp)
{temp1=temp;
temp=a[i-1];
a[i-1]=temp;
}
else
{a[i-1]=temp;
}
}
for(int i=0;i<n;i++)
cout<<a[i]<<" ";

}
int main()
{int arr[]={};
replacelarge(arr,6);
}
