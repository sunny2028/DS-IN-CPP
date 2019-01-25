#include<bits/stdc++.h>//https://www.geeksforgeeks.org/sort-a-stack-using-recursion/d
using namespace std;
void sortedpush(stack<int>&s,int temp )
{if(s.empty()||temp<s.top())
s.push(temp);
else
{int ele=s.top();
s.pop();
sortedpush(s,temp);
s.push(ele);
}
}
void sort(stack<int>&s)
{if(!s.empty())
{int temp=s.top();
s.pop();
sort(s);
sortedpush(s,temp);
}
}
int main()
{stack<int>s;
s.push(30);
s.push(-5);
s.push(18);
s.push(4);
s.push(-3);
sort(s);
int j=s.size();
for(int i=0;i<j;i++)
{cout<<s.top()<<" ";
s.pop();
}
}
