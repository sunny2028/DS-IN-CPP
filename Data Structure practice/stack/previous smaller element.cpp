#include<bits/stdc++.h>
using namespace std;
void printNGE(int a[],int n)
{stack<int>s;
int ls[n];
s.push(a[0]);
ls[0]=0;
for(int i=1;i<n;i++)
{while(!s.empty()&&s.top()>=a[i])
{
s.pop();
}
if(s.empty())
{
ls[i]=0;
s.push(a[i]);
}
else
{
ls[i]=s.top();
s.push(a[i]);
}
}
for(int i=0;i<n;i++)
cout<<ls[i]<<" ";
}
int main()
{ int arr[] = {2, 4, 8, 7, 7, 9, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    return 0;


}
