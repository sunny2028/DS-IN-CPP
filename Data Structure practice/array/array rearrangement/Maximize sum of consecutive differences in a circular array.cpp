#include<bits/stdc++.h>
using namespace std;
int main()
{int a[]={ 4, 2, 1, 8 },b[4],i,n=4;
int flag=true;
sort(a,a+4);
int start=0,end=3;
for(i=0;i<n;i++)
{if(flag)
{b[i]=a[start++];
   }
else
{b[i]=a[end--];
}
flag=!flag;
}
int sum=0;
for(i=0;i<n-1;i++)
{sum=sum+abs(b[i]-b[i+1]);

}
sum=sum+abs(b[n-1]-b[0]);
cout<<sum;


}


