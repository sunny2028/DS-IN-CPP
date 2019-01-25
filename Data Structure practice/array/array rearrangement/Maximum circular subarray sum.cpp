#include<iostream>//https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/
using namespace std;//TIME complexity:O(n) auxiliary space:O(1)
int kadane(int a[],int n)
{int maxsofar=0,maxendinghere=0;
for(int i=1;i<n;i++)
{maxendinghere=maxendinghere+a[i];
if(maxendinghere<0)
 maxendinghere=0;
 else if(maxsofar<maxendinghere)
 maxsofar=maxendinghere;
 }
 return maxsofar;
 }

int maxcircularsum(int a[],int n)
{
int sum=0,max_wrapping;
int max_straight=kadane(a,n);
for(int i=0;i<n;i++)
{sum=sum+a[i];
a[i]=-a[i];
}
max_wrapping=sum-(-kadane(a,n));
return (max_straight>max_wrapping)?max_straight:max_wrapping;


}
int main()
{int arr[]={11, 10, -20, 5, -3, -5, 8, -13, 10};
cout<<maxcircularsum(arr,9);

}
