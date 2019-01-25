#include<iostream>
#include<stack>
using namespace std;
void printNGE(int a[],int n)
{stack<int>s;
int element,next;
s.push(a[0]);

for(int i=1;i<n;i++)
{
if(!s.empty())
    { next=a[i];
element=s.top();
s.pop();
        while(element<next)
        {
            cout<<element<<" -> "<<next<<"\n";
            if(s.empty())
                break;
                 element=s.top();
                s.pop();


        }
        if(element>next)
            s.push(element);

    }
    s.push(a[i]);

}
while(!s.empty())
{
    cout<<s.top()<<" -> "<<-1<<"\n";
    s.pop();

}
}
int main()
{
int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
}
