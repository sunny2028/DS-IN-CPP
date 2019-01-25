#include<bits/stdc++.h>//https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
using namespace std;//time complexity:O(n)
int getmaxarea(int hist[],int n)
{stack<int>s;
int i=0,areawithtop,maxarea=0;
while(i<n)
{if(s.empty()||hist[s.top()]<=hist[i])
s.push(i++);
else
{int top=s.top();
s.pop();
 areawithtop=hist[top]*(s.empty() ? i:i-s.top()-1);
if(areawithtop>maxarea)
{
maxarea=areawithtop;
}
}
}
while(!s.empty())
{int tp=s.top();
s.pop();
areawithtop=hist[tp]*(s.empty()?i:i-s.top()-1);
if(areawithtop>maxarea)
{
maxarea=areawithtop;
}
}
return maxarea;
}
int main()
{int hist[]={6, 2, 5, 4, 5, 1, 6};
cout<<getmaxarea(hist,7);
}
