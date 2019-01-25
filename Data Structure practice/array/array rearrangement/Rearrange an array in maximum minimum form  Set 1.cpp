#include<iostream>
using namespace std;
int main()
{int a[]={1,2,3,4,5,6,7,8};
int start=0,end=7;
while(start<end)
{cout<<a[end--]<<" "<<a[start++]<<" ";
}
if(sizeof(a)%2!=0)
cout<<a[start];
}
