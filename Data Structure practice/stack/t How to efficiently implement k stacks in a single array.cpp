#include<iostream>//https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/
using namespace std;
class stack
{int *arr,*temp,*next;
int free;
public:stack(int n,int k);
   void push(int x,int sn);
    bool isfull()
    {return(free==-1);
    }
    bool isempty(int sn)
    {
    return(temp[sn]==-1);
    }
    int pop(int sn);
};
stack::stack(int n,int k)
{arr=new int[n];
temp=new int[k];
next=new int[n];
for(int i=0;i<k;i++)
temp[i]=-1;
for(int i=0;i<n-1;i++)
{next[i]=i+1;
}
next[n-1]=-1;
free=0;
}
void stack::push(int x,int sn)
{if(isfull())
{cout<<"stack overflow\n";
return;
}
int i=free;
free=next[i];
next[i]=temp[sn];
temp[sn]=i;
arr[i]=x;
}
int stack::pop(int sn)
{if(isempty(sn))
{cout<<"stack underflow\n";
return -1;
}
int i=temp[sn];
temp[sn]=next[i];
next[i]=free;
free=i;
return arr[i];
}
int main()
{stack s(10,3);
s.push(1,0);
s.push(2,1);
s.push(3,0);
s.push(4,2);
s.push(5,2);
s.push(6,2);
s.push(7,1);
cout<<s.pop(1)<<"\n";
cout<<s.pop(2)<<"\n";
cout<<s.pop(0)<<"\n";
cout<<s.pop(0)<<"\n";
cout<<s.pop(2)<<"\n";
}
