#include<iostream>
#include<cmath>
using namespace std;
int main()
{long long int m,n,k,u;
cin>>m>>n;
u=pow(2,31);
int l=0;
while(l<32)
{k=m&1;
m=m>>1;
if(k==1)
m=m|u;
if(m==n)
{cout<<"yes";
break;
}
l++;
}
if(l==32)
cout<<"no";
}
