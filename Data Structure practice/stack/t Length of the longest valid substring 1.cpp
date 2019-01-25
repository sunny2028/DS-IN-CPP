#include<bits/stdc++.h>
using namespace std;
int findMaxLen(string str)
{int result=0;
stack<int>s;
for(int i=0;i<str.length();i++)
{if(str[i]=='(')
s.push(i);
else
{
    if(!s.empty())
{
result=max(result,i-s.top());
s.pop();
}
}
}
return result*2;
}
int main()
{string str = "((()()";
    cout << findMaxLen(str) << endl;

    str = "()(()))))";
    cout << findMaxLen(str) << endl ;

    return 0;
}
