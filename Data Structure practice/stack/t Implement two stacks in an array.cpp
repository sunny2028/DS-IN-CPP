#include<iostream>//https://www.geeksforgeeks.org/implement-two-stacks-in-an-array/
using namespace std;
class stack
{int *arr;
int top1;
int top2;
int size;
public:stack(int x)
{arr=new int[x];
top1=-1;
top2=x;
size=x;
}
int push1(int x)
{if(top1<top2-1)
arr[++top1]=x;
else
{
cout<<"stack overflow";
return -1;
}

}
int push2(int x)
{if(top1<top2-1)
arr[--top2]=x;
else
{cout<<"stack overflow";
return -1;
}
}
int pop1()
{if(top1>=0)
return arr[top1--];
else
return -1;
}
int pop2()
{if(top2<size)
return arr[top2++];
else
return -1;
}
};
int main()
{stack s(10);
s.push1(2);
s.push2(3);
s.push1(1);
s.push2(8);
cout<<s.pop1()<<"\n";
cout<<s.pop2()<<"\n";
cout<<s.pop2();
}
