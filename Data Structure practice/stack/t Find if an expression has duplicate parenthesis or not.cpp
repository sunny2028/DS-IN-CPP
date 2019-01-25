#include<bits/stdc++.h>//https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/
using namespace std;
bool findDuplicateparenthesis(string str)
{stack<char>s;
for(int i=0;i<str.length();i++)
{if(str[i]=='('||str[i]>='a'&& str[i]<='z'||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
s.push(str[i]);
else
{if(s.top()=='(')
 return true;
while(s.top()!='(')
{s.pop();
}
s.pop();
}
}
return false;
}
int main()
{string str = "(((a+(b))+(c+d)))";

    if (findDuplicateparenthesis(str))
        cout << "Duplicate Found ";
    else
        cout << "No Duplicates Found ";

    return 0;
}
