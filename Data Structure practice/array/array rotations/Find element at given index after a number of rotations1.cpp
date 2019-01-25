#include<bits/stdc++.h>
using namespace std;
int finde(int arr[],int rotator[2][2],int index,int n,int rotations)
{int left,right;
for(int i=rotations-1;i>=0;i--)
{left=rotator[i][0];
right=rotator[i][1];
if(index>=left&&index<=right)
{if(index==left)
index=right;
else
index--;
}
}
return arr[index];
}

int main()
{int arr[]={1,2,3,4,5};
int n=sizeof(arr)/sizeof(arr[0]);
int rotator[][2]={{0,2},{0,3}};
int rotations=2;
int index;
cin>>index;
cout<<finde(arr,rotator,index,n,rotations);
return 0;
}
