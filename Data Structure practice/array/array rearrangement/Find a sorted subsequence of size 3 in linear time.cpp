#include<iostream>//time complexity:O(n) Auxiliary space:O(n)
using namespace std;//https://www.geeksforgeeks.org/find-a-sorted-subsequence-of-size-3-in-linear-time/
int check3(int a[],int n)
{int less[n],large[n];
int min=0;
less[min]=-1;
int max=n-1;
for(int i=1;i<n;i++)
{if(a[i]<a[min])
{less[i]=-1;
min=i;
}
else
less[i]=min;
}
large[max]=-1;
for(int i=n-2;i>=0;i--)
{if(a[i]>a[max])
{large[i]=-1;
max=i;
}
else
large[i]=max;
}

 for (int i = 0; i < n; i++)
   {
       if (less[i] != -1 && large[i] != -1)
       {
          cout<<a[less[i]]<<" "<<a[i]<<" "<<a[large[i]];
          return 1;
       }
   }
   cout<<"no triplet found";
   return 0;



}

int main()
{ int arr[] = {12, 11, 10, 5, 6, 2, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    check3(arr, n);
    return 0;
}
