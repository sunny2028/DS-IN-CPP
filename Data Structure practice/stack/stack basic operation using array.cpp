#include<iostream>
using namespace std;
class stack
{int size;
int *arr;
int top=-1;
public :
stack(int capacity);
bool isfull()
{
return (top==size-1);
}
bool isempty()
{
return (top==-1);
}
void push(int x);
int pop();
};
stack::stack(int max)
{
arr=new int[max];
size=max;
}
void stack::push(int x)
{if(top>=size)
{
cout<<"stack overflow";
return;

}
top++;
arr[top]=x;
}
int stack::pop()
{if(top<0)
{
cout<<"stack underflow";
return -1;
}
int x=top;
top--;
return arr[x];
}
int main()
{stack s(3);
s.push(3);
s.push(2);
s.push(1);
cout<<s.isfull()<<"\n";
cout<<s.pop()<<" "<<s.pop();

cout<<"\n"<<s.isempty();
}





