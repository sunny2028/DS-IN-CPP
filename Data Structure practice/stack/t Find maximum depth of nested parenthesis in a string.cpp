#include<bits/stdc++.h>
using namespace std;
int countmax(string s)
{int j=s.length();
stack<char>v;
int count=0,maxcount=0;
for(int i=0;i<j;i++)
{if(s[i]=='(')
{v.push(s[i]);
count=0;
}
if(s[i]==')')
{char j=v.top();
v.pop();
count++;
}
if(count>maxcount)
    maxcount=count;
}
if(!v.empty())
{cout<<v.top();
    return -1;
}
return maxcount;

}
int main()
{string s="( ((X)) (((Y))) )";
cout<<countmax(s);
}
