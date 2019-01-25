#include<iostream>//https://www.geeksforgeeks.org/stack-in-cpp-stl/
#include<stack>>
using namespace std;
void show(stack<int>r)
{stack<int>k=r;
while(!k.empty())
{cout<<k.top();
k.pop();
}
}
int main()
{stack<int>s;
s.push(6);
s.push(5);
s.push(4);
s.push(3);
s.push(2);
s.push(1);
cout<<s.size()<<"\n";
cout<<s.top()<<"\n";

s.pop();
show(s);

}
