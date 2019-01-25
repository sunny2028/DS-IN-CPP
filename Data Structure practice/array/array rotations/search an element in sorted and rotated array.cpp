#include<iostream>
using namespace std;  //TIME COMPLEXITY:O(logn)

int pivotsearch(int a[],int l,int h)
{if(l>h)
return -1;
if(l==h)
return l;
int mid=(l+h)/2;
if(mid<h&&a[mid]>a[mid+1])
return mid;
if(mid>l&&a[mid]<a[mid-1])
return mid-1;
if(a[mid]>a[l])
return pivotsearch(a,mid+1,h);
return pivotsearch(a,l,mid-1);
}

int binarysearch(int a[],int l,int h,int key)
{int mid=(l+h)/2;
   if(a[mid]==key)
   return mid;
   if(a[mid]>key)
   return binarysearch(a,l,mid-1,key);
   return binarysearch(a,mid+1,h,key);

}

int pivotbinarysearch(int a[],int n,int key)
{int pivot=pivotsearch(a,0,n-1);
if(pivot==-1)
return binarysearch(a,0,n-1,key);
if(a[pivot]==key)
return pivot;
if(a[0]<=key)
return binarysearch(a,0,pivot-1,key);
return binarysearch(a,pivot+1,n-1,key);
}



int main()
{int a[]={3,4,5,6,1,2};
int l=pivotbinarysearch(a,6,2);
cout<<l;
}
