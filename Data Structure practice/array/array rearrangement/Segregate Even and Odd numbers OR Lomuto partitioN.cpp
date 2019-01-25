#include<bits/stdc++.h>//https://www.geeksforgeeks.org/segregate-even-and-odd-numbers/
using namespace std;//Time Complexity: O(n)
void segregate(int a[],int n)
{int j=-1;
for(int i=0;i<n;i++)
{if(a[i]==0)
{j++;
swap(a[j],a[i]);
}
}
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
}
int main()
{int arr[]={1,2,3,4,5,6,7};
segregate(arr,7);

}
