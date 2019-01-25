#include<bits/stdc++.h>//https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/
using namespace std;
void sortstack(stack<int>&s)
{stack<int>p;

while(!s.empty())
{int j=s.top();
s.pop();
if(p.empty())
p.push(j);
else
{int k=p.top();
while(k<j)
{p.pop();
s.push(k);
if(!p.empty())
k=p.top();
else
    break;
}
p.push(j);
}
}
s=p;

}
int main()
{   stack<int>input;
    input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);
    sortstack(input);
    int j=input.size();
    for(int i=0;i<j;i++)
    {cout<<input.top()<<"  ";
    input.pop();
    }
}
