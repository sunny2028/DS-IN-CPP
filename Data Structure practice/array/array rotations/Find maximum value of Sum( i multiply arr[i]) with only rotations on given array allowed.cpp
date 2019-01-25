#include<iostream>
using namespace std; //TIME COMPLEXITY: O(n)

int findmax(int a[],int n)   //https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/
{
    int i,sum=0,Ri=0,maxi;
    for(i=0;i<n;i++)
    { sum+=a[i];
     Ri=Ri+(i*a[i]);
    }
    maxi=Ri;
    for(i=1;i<n;i++)
    {
        Ri=Ri+sum-n*a[n-i];
          if(Ri>maxi)
          {
              maxi=Ri;
          }
    }
    return maxi;
}
int main()
{ int a[]={10,1,2,3,4,5,6,7,8,9};
int k;
k=findmax(a,10);
cout<<k;

}
