#include<bits/stdc++.h>
using namespace std;
void printNGE(int a[],int n)
{stack<int>s;
s.push(a[0]);
for(int i=1;i<n;i++)
{while(!s.empty()&&s.top()<a[i])
{cout<<s.top()<<"->"<<a[i]<<"\n";
s.pop();
}
s.push(a[i]);
}
while(!s.empty())
{
cout<<s.top()<<"-> -1\n";
s.pop();
}
}
int main()
{ int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    return 0;


}
