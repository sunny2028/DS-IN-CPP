#include<iostream>
using namespace std;
class stack
{int data;
int a[100];
int top;
public:stack()
            {top=-1;
            }
bool isfull()
{return (top==99);
}
bool isempty()
{return(top==-1);
}
void push(int );
int pop();
};
void stack::push(int x)
{if(isfull())
return;
top++;
a[top]=x;
}
int stack::pop()
{if(isempty())
return -1;
return a[top--];
}
class specialstack:public stack
{stack min;
public:void push(int x);
        int pop();
        int gmin();

};
void specialstack::push(int x)
{stack::push(x);
if(min.isempty())
{min.push(x);
}
else
{int y=min.pop();
if(y>x)
{min.push(y);
min.push(x);
}
else
    min.push(y);
}
}
int specialstack::pop()
{if(isempty())
 return -1;
 int x=stack::pop();
 int y=min.pop();
 if(x!=y)
 min.push(y);
return x;
 }
int specialstack::gmin()
{int a=min.pop();
min.push(a);
return a;
}
int main()
{specialstack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
cout<<s.gmin();
cout<<s.pop();
cout<<s.gmin();



}

