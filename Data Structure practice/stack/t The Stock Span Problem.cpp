#include<iostream>
#include<stack>
using namespace std;
int * stockspan(int a[],int n,int st[])
{stack<int> s;
s.push(0);
st[0]=1;
for(int i=1;i<n;i++)
{while(!s.empty()&&a[s.top()]<=a[i])
  s.pop();
  if(s.empty())
    st[i]=i+1;
    else
    st[i]=i-s.top();
    s.push(i);
}
return st;
}
int main()
{int a[]={100,80,60,70,60,75,85};
int s[7];
int *p=stockspan(a,7,s);
for(int i=0;i<7;i++)
{cout<<*(p+i)<<" ";
}
}
