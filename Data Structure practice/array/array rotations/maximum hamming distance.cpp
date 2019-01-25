#include<iostream>//time complexity:O(n*n);
//https://www.geeksforgeeks.org/find-a-rotation-with-maximum-hamming-distance/
using namespace std;
int find(int arr[],int n)
{int temp[2*n],i,j,k,maxi,currham;
for(i=0;i<n;i++)
temp[i]=temp[i+n]=arr[i];
maxi=0;
for(i=1;i<n;i++)
{currham=0;
for(j=i,k=0;j<i+n;j++,k++)
if(temp[j]!=arr[k])
currham++;
maxi=max(currham,maxi);
}
return maxi;

}
int main()
{int k;
int arr[]={1,4,1};
k=find(arr,3);
cout<<k<<"\n";



}
