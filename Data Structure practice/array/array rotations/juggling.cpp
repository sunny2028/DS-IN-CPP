#include<iostream>
using namespace std;
int gcd(int a,int b)
{if(a%b==0)
return b;
return(b,a%b);
}
void rotate(int arr[],int n,int d)
{int k,j;
for(int i=0;i<gcd(n,d);i++)
{int temp=arr[i];
j=i;
while(1)
{k=j+d;
if(k>=n)
k=k-n;
if(k==i)
    break;
arr[j]=arr[k];
j=k;
}
arr[j]=temp;
}
}
int main()
{int arr[]={1,2,3,4,5,6,7};
rotate(arr,7,2);
for(int i=0;i<7;i++)
cout<<arr[i]<<" ";
}
