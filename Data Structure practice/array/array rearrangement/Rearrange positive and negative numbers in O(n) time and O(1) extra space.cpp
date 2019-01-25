#include<bits/stdc++.h>
using namespace std;      //https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/
void rearrange(int a[],int n)
{int i=-1,j;
for(j=0;j<n;j++)
{if(a[j]<0)
   {

    i++;
    swap(a[i],a[j]);
   }
 }
 for(int i=0;i<n;i++)
   cout<<a[i]<<" ";
   cout<<"\n";
 int neg=0,pos=i+1;
 while(pos<n&&neg<pos&&a[neg]<0)
 {swap(a[pos],a[neg]);
 pos++;
 neg+=2;
 }
}

void printarray(int a[],int n)
{for(int i=0;i<n;i++)
   cout<<a[i]<<" ";


}


int main()
{int arr[]={-1, 2, -3, 4, 5, 6, -7, 8, 9};
rearrange(arr,9);
printarray(arr,9);
}
