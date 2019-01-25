#include<bits/stdc++.h>
using namespace std;
#define N 8
bool matrix[N][N]={   {0, 0, 1, 0},
                      {0, 0, 1, 0},
                      {0, 0, 0, 0},
                      {0, 0, 1, 0}};
bool knows(int a,int b)
{
return matrix[a][b];
}
int findcelebrity(int n)
{stack<int>s;
for(int i=0;i<n;i++)
s.push(i);
int a,b,c;
a=s.top();
s.pop();
b=s.top();
s.pop();
while(s.size()>0)
{if(knows(a,b))
{a=s.top();
s.pop();
}
else
{b=s.top();
s.pop();
}
}
if(knows(a,b))
c=b;
else
c=a;
for(int i=0;i<n;i++)
{if(i!=c&&(knows(c,i)||!knows(i,c)))
     return -1;
}
return c;
}

int main()
{int j=findcelebrity(4);
if(j==-1)
cout<<"no celebrity";
else
cout<<j;
}
