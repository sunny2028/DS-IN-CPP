#include<bits/stdc++.h>//https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
using namespace std;//time complexity:O(1) auxiliary space :O(1)
struct mystack
{stack<int>s;
int minele;
int maxele;
void push(int x)
{if(s.empty())
{s.push(x);
minele=x;
maxele=x;
}
else
{if(x<minele)
{s.push(2*minele-x);
minele=x;
}
else if(x>maxele)
{s.push(2*x-maxele);
maxele=x;
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
else if(y>maxele)
maxele=2*maxele-y;
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
{if(k>maxele)
return maxele;
else
return k;
}
}
int min()
{
return minele;
}
int max()
{return maxele;
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
cout<<s.max()<<"\n";
s.pop();
cout<<s.min()<<"\n";
cout<<s.max();
}


