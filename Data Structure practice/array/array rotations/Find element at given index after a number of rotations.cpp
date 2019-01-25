#include<bits/stdc++.h>
using namespace std;
rotater(int a[],int l,int h,int n)
{int start=l;
int endi=h;
while(start<=endi)
{swap(a[start],a[endi]);
 start++;
 endi--;
}
}
void finder(int arr[],int rot[2][2],int n,int index)
{for(int i=0;i<2;i++)
 {rotater(arr,rot[i][0],rot[i][1]-1,n);
 rotater(arr,rot[i][0],rot[i][1],n);
 }
 cout<<arr[index];
}
int main()
{int arr[]={1,2,3,4,5};
int index;
int rot[2][2]={{0,2},{0,3}};
cin>>index;
finder(arr,rot,5,index);
return 0;
}
