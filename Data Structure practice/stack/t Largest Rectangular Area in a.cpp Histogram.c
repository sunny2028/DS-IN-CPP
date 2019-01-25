#include<bits/stdc++.h>
using namespace std;
int getmaxarea(int hist[],int n)
{stack<int>s;
int i,maxarea=0;
while(i<n)
{if(s.empty()||hist[s.top]<=hist[i])
s.push(i++);
else
{int top=s.top();
s.pop();
int areawithtop=hist[top]*(s.empty() ? i:i-s.top()-1);
if(areawithtop>maxarea)
{
maxarea=areawithtop;
}
}
}
while(!s.empty())
{int tp=s.top();
s.pop();
areawithtop=hist[tp]*(s.empty()?i:i=s.top()-1);
if(areawithtop>maxarea)
{
maxarea=areawithtop;
}
}
return maxarea;
}
int main()
{int hist[]={6, 2, 5, 4, 5, 1, 6};
cout<<getmaaxarea(hist,7);
}
