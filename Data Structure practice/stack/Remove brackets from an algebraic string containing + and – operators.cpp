#include<bits/stdc++.h>//https://www.geeksforgeeks.org/remove-brackets-algebraic-string-containing-operators/
using namespace std;
string simplify(string str)
{stack<int>s;
string str1;
s.push(0);
for(int i=0;str[i]!='\0';i++)
{if(str[i]=='+')
{
    if(s.top()==0)
    str1=str1+'+';
    else
        str1=str1+'-';
}
else if(str[i]=='-')
{
    if(s.top()==0)
    str1=str1+'-';
    else
        str1=str1+'+';
}
else if(str[i]=='('&&i>0)
{

    if(str[i-1]=='-')
    {
        if(s.top()==1)
          s.push(0);
          else
            s.push(1);
    }
    if(str[i-1]=='+')
        s.push(s.top());
}
else if(str[i]==')')
    s.pop();
else
    str1=str1+str[i];
}
return str1;
}
int main()
{string s1 = "a-(b+c)";
    string s2 = "a-(b-c-(d+e)-c)-f";
    cout << simplify(s1) << endl;
    cout << simplify(s2) << endl;
    return 0;
}
