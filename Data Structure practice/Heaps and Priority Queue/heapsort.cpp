#include<bits/stdc++.h>
using namespace std;
struct heap
{
	int *arr;
	int count;
	int capacity;
};
heap* createheap(int c)
{
	heap* h=new heap;
	h->count=0;
	h->capacity=c;
	h->arr=new int[c];
	return h;
}
int leftchild(heap* h,int i)
{
	int l=2*i+1;
	if(l>=h->count)
	return -1;
	return l;
}
int rightchild(heap* h,int i)
{
	int r=2*i+2;
	if(r>=h->count)
	return -1;
	return r;
}
void procolatedown(heap* h,int i)
{
	if(i>=h->count||i<0)
	return ;
	int l=leftchild(h,i);
	int r=rightchild(h,i);
	int max;
	if(l!=-1&&h->arr[l]>h->arr[i])
	   max=l;
	   else
	   {
	   max=i;
}
if(r!=-1&&h->arr[r]>h->arr[max])
max=r;
    if(max!=i)
    {
    	int temp=h->arr[i];
    	h->arr[i]=h->arr[max];
    	h->arr[max]=temp;
    	procolatedown(h,max);
    
	}
}
void buildheap(heap* h,int arr[],int n)
{
	if(h==NULL)
	return;
     for(int i=0;i<n;i++)
     {
     	h->arr[i]=arr[i];
	 }
	 h->count=n;
	 for(int i=(n-2)/2;i>=0;i--)
	 procolatedown(h,i);
}
void heapsort(int *arr,int n)
{
	heap* h=createheap(n);
	buildheap(h,arr,n);
	for(int i=n-1;i>=0;i--)
	{     int temp=h->arr[i];
		h->arr[i]=h->arr[0];
		arr[i]=h->arr[i];
		h->arr[0]=temp;
		h->count--;
		procolatedown(h,0);
	}
}
int main()
{
	int arr[]={1,4,6,3,9};
	heapsort(arr,5);
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
}
