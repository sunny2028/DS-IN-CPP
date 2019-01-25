#include<bits/stdc++.h>
using namespace std;

bool check(int x,int y)
{
unsigned long long int x64=x|(unsigned long long int)x;
while(x64>=y)
{if((unsigned)x64==y)
return true;
x64>>=1;
}
return false;
}
int main()
{int m,n;
cin>>m>>n;
if(check(m,n))
cout<<"yes";
else
cout<<"no";
}
