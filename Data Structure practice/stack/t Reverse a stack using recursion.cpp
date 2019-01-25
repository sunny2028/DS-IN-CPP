#include<bits/stdc++.h>//https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/
using namespace std;
void insertelementatbottom(stack<int>&s,int temp )
{if(s.empty())
s.push(temp);
else
{int ele=s.top();
s.pop();
insertelementatbottom(s,temp);
s.push(ele);
}
}
void reverse(stack<int>&s)
{if(!s.empty())
{int temp=s.top();
s.pop();
reverse(s);
insertelementatbottom(s,temp);
}
}
int main()
{stack<int>s;
s.push(4);
s.push(3);
s.push(2);
s.push(1);
reverse(s);
int j=s.size();
for(int i=0;i<j;i++)
{cout<<s.top()<<" ";
s.pop();
}
}
