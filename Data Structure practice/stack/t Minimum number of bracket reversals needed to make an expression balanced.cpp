#include<bits/stdc++.h>//https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/
using namespace std;
int countMinReversals(string str)
{int len=str.length();
if(len%2==1)
{
return -1;
}
stack<char>s;
for(int i=0;i<len;i++)
{if(str[i]=='{')
s.push(str[i]);
else
{if(s.empty())
s.push(str[i]);
else if(s.top()=='{')
  s.pop();
  else
  s.push(str[i]);

}
}
int len1=s.size();
int count=0;
for(int i=0;i<len1;i++)
{if(s.top()=='{')
   {s.pop();
     count++;
    }
    else
    break;

}
return len1/2 + count%2; // return ceil(m/2) + ceil(n/2) which is
    // actually equal to (m+n)/2 + n%2 when
    // m+n is even.
}
int main()
{string expr = "}}{{";
   cout << countMinReversals(expr);
   return 0;



}
