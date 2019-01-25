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
{q1.push(x);
size++;
}
void Stack::pop()
{
while(q1.size()!=1)
{q2.push(q1.front());
q1.pop();
}
q1.pop();
size--;
queue<int>q=q1;
q1=q2;
q2=q;
}
int Stack::top()
{while(q1.size()!=1)
{q2.push(q1.front());
q1.pop();
}
int temp=q1.front();
q2.push(temp);
q1.pop();
queue<int>q=q1;
q1=q2;
q2=q;
return temp;
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
cout<<s.top()<<"\n";
s.push(6);
cout<<s.sizeofstack()<<"\n";
s.pop();
cout<<s.sizeofstack()<<"\n";



}
