#include<bits/stdc++.h>//https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
using namespace std;//time complexity:O(1) auxiliary space :O(1)
struct mystack
{stack<int>s;
int minele;
void push(int x)
{if(s.empty())
{s.push(x);
minele=x;
}
else
{if(x<minele)
{s.push(2*x-minele);
minele=x;
}
else
{
s.push(x);
}
}
}
void pop()
{if(s.empty())
{cout<<"stack underflow";
return;
}
else
{int y=s.top();
s.pop();
if(y<minele)
minele=2*minele-y;
}
}
int peek()
{if(s.empty())
{cout<<"stack underflow";
return -1;
}
int k=s.top();
if(k<minele)
return minele;
else
return k;
}
int min()
{
return minele;
}
};
int main()
{mystack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.push(6);
cout<<s.peek()<<"\n";
cout<<s.min()<<"\n";
s.pop();
cout<<s.min()<<"\n";
}


