#include<bits/stdc++.h>
using namespace std;
class Stack
{int size;
queue<int>q1,q2;
public:
Stack()
{
size=0;
}
void push(int x);
void pop();
int top();
int sizeofstack();
};
void Stack::push(int x)
{q2.push(x);
size++;
while(!q1.empty())
{q2.push(q1.front());
q1.pop();
}
queue<int>q=q1;
q1=q2;
q2=q;
}
void Stack::pop()
{
q1.pop();
size--;
}
int Stack::top()
{return q1.front();
}
int Stack::sizeofstack()
{
return q1.size();
}
int main()
{Stack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
cout<<s.sizeofstack()<<"\n";
s.pop();
cout<<s.top();

}
