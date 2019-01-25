#include<iostream>
using namespace std;

bool check(int a[],int n,int sum) //TIME COMPLEXITY:O(n)
{ int i;  //https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
for(i=0;i<n;i++)
    if(a[i]>a[i+1])
    break;
int l=(i+1)%n;
int r=i;
while(l!=r)
{ if(a[l]+a[r]==sum)
     return true;
    if(a[l]+a[r]>sum)
    r=(n+r-1)%n;
    else
        l=(l+1)%n;

}
   return false;

}

int main()
{ int a[]={3,4,5,6,1,2};
bool b;
   b=check(a,6,33);
   cout<<b;

}
