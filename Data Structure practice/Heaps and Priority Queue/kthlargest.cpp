#include<iostream>
using namespace std;
struct heap
{
	int *arr;
	int count;
	int capacity;
	int heaptype;
};
heap* createheap(int c)
{
	heap* nn=new heap;
	nn->count=0;
	nn->capacity=c;
	nn->arr=new int[c];
	return nn;
}
int parent(heap* h,int i)
{   
if(i>=h->count||i<0)
return -1;
	return(i-1)/2;
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
	int l;int r;int min;
	 l=leftchild(h,i);
	 r=rightchild(h,i);
	 if(l!=-1&&h->arr[l]<h->arr[i])
	 min=l;
	 else
	 min=i;
	 if(r!=-1&&h->arr[r]<min)
	 min=r;
	 if(min!=i)
	 {
	 	int temp=h->arr[i];
	 	h->arr[i]=h->arr[min];
	 	h->arr[min]=temp;
	 	procolatedown(h,min);
	 }
}
void resizeheap(heap* h)
{
	int *arr_old=h->arr;
	h->arr=new int[h->capacity*2];
	for(int i=0;i<h->capacity;i++)
	{
		h->arr[i]=arr_old[i];
	}
	h->capacity=h->capacity*2;
	delete arr_old;
}
int deletemin(heap* h)
{
	if(h->count==0)
	return -1;
	int temp=h->arr[0];
	h->arr[0]=h->arr[h->count-1];
	h->count--;
	procolatedown(h,0);
	return temp;
}
void insert(heap* h,int d)
{
	if(h->count==h->capacity)
	resizeheap(h);
	h->count++;
	int i=h->count-1;
	while(i>0&&d<h->arr[(i-1)/2])
	{
		h->arr[i]=h->arr[(i-1)/2];
		i=(i-1)/2;
	}
	h->arr[i]=d;
}
void buildheap(heap* h,int arr[],int n)
{
	if(h==NULL)
	return ;
	for(int i=0;i<n;i++)
	{
		h->arr[i]=arr[i];
	}
	h->count=n;
		
	for(int i=(n-2)/2;i>=0;i--)
	 {
	 	procolatedown(h,i);
	 }
	 
}
int kthlargest(int *arr,int n,int k)
{
	heap* h=createheap(k);
	buildheap(h,arr,k);
	for(int i=k;i<n;i++)
	 if(arr[i]>h->arr[0])
	 {
	 	h->arr[0]=arr[i];
	 	procolatedown(h,0);
	 }
	 return h->arr[0];
	
}
int main()
{
	int arr[]={1,5,7,2,9};
	cout<<kthlargest(arr,5,5);
}
