#include<iostream>  //time complexity:O(n*n)
using namespace std;//auxilary space:O(1)
void arrange(int a[],int n)//https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/
{int key,j;
for(int i=1;i<n;i++)
{key=a[i];
j=i-1;
if(key>0)
 continue;
 while(j>=0&&a[j]>0)
 {a[j+1]=a[j];
 j=j-1;
 }
a[j+1]=key;
}
}
void print(int a[],int n)
{for(int i=0;i<n;i++)
cout<<a[i]<<" ";
}
int main()
{int arr[]={12,11,-13,-5,6,-7,5,-3,-6};
arrange(arr,9);
print(arr,9);





}
