#include<iostream>
using namespace std;
void merge(int arr[],int l,int m,int r)
{
int n1=m-l+1;
int n2=r-m;
int a[n1],b[n2];
for(int i=0;i<n1;i++)
{
    a[i]=arr[l+i];

}
for(int i=0;i<n2;i++)
{
    b[i]=arr[m+1+i];

}
int i=0,j=0,k=l;
while(i<n1&&j<n2)
{

    if(a[i]<b[j])
    {
        arr[k++]=a[i++];

    }
    else
    {

        arr[k++]=b[j++];
    }
}
while(i<n1)
    arr[k++]=a[i++];
while(j<n2)
    arr[k++]=b[j++];

}
void mergesort(int arr[],int l,int r)
{
   if(l<r)
    {
       int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);

    }
}
int main()
{int arr[]={2,3,4,5,1,8,6,7};
 mergesort(arr,0,7);
 for(int i=0;i<8;i++)
    cout<<arr[i]<<" ";
}
