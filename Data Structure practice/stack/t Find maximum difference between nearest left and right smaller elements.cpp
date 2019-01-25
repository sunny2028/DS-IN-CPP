#include<bits/stdc++.h>//https://www.geeksforgeeks.org/find-maximum-difference-between-nearest-left-and-right-smaller-elements/
using namespace std;
void findSmaller(int arr[],int n,int ne[])
{stack<int>s;
for(int i=0;i<n;i++)
{while(!s.empty()&&s.top()>arr[i])
         s.pop();
         if(s.empty())
         ne[i]=0;
         else
         ne[i]=s.top();
         s.push(arr[i]);
}
}
int findMaxDiff(int arr[],int n)
{int LS[n];
findSmaller(arr,n,LS);
int RS[n];
reverse(arr,arr+n);
findSmaller(arr,n,RS);
int result=-1;
for(int i=0;i<n;i++)
{
result=max(result,abs(LS[i]-RS[n-i-1]));
}
return result;
}
int main()
{ int arr[] = {2, 4, 8, 7, 7, 9, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum diff :  "
         << findMaxDiff(arr, n) << endl;
    return 0;
}
