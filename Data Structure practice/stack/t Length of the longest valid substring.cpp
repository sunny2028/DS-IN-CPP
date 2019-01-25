#include<bits/stdc++.h>
using namespace std;
int findMaxLen(string str)
{int result=0;
stack<int>s;
s.push(-1);
for(int i=0;i<str.length();i++)
{if(str[i]=='(')
s.push(i);
else
{s.pop();
    if(!s.empty())
{
result=max(result,i-s.top());
}
else
    s.push(i);
}
}
return result;
}
int main()
{string str = "((()()";
    cout << findMaxLen(str) << endl;

    str = "()(()))))";
    cout << findMaxLen(str) << endl ;

    return 0;
}
