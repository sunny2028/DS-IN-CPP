#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int findpivot(int arr[],int l,int r)
{int pivot=arr[r];
int j=l-1;
for(int i=l;i<=r-1;i++)
{
    if(arr[i]<=pivot)
    {j++;
        swap(arr[i],arr[j]);
    }
}
swap(arr[j+1],arr[r]);
return j+1;


}
void quicksort(int arr[],int l,int r)
{if(l<r)
{
    int pivot=findpivot(arr,l,r);
    quicksort(arr,l,pivot-1);
    quicksort(arr,pivot+1,r);

}
}
int main()
{int arr[]={2,3,4,5,1,8,6,7};
 quicksort(arr,0,7);
 for(int i=0;i<8;i++)
    cout<<arr[i]<<" ";
}
