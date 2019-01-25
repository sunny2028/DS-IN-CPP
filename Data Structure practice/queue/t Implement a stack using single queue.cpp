#include<bits/stdc++.h>//https://www.geeksforgeeks.org/implement-a-stack-using-single-queue/
using namespace std;
class Stack
{queue<int>q;
int size;
public:
void push(int x)
{int size=q.size();
q.push(x);
while(size>1)
{q.push(q.front());
 q.pop();
 size--;
}
}
void pop()
{if(q.size()==0)
{
cout<<"underflow";
return ;
}
q.pop();
}
int top()
{
if(q.front())
return q.front();
}
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    cout << s.top() << endl;
    s.pop();
    s.push(30);
    s.pop();
    cout << s.top() << endl;
    return 0;


}
