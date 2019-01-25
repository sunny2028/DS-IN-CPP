#include<bits/stdc++.h>
using namespace std;
int countmax(string s)
{int j=s.length();
int count=0,maxcount=0;
for(int i=0;i<j;i++)
{if(s[i]=='(')
{
count++;
if(count>maxcount)
maxcount=count;
}
if(s[i]==')')
{if(count>0)
count--;
else
return -1;
}
}
if(count!=0)
return -1;
return maxcount;
}
int main()
{string s="( ((X)) (((Y))) )";
cout<<countmax(s);
}
