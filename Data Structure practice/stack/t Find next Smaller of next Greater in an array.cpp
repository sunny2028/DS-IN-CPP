#include<bits/stdc++.h>//https://www.geeksforgeeks.org/find-next-smaller-next-greater-array/
using namespace std;
void next(int a[],int n,int r[],char c)
{stack<int>s;
for(int i=n-1;i>=0;i--)
{while(!s.empty()&&((c=='g')?a[s.top()]<a[i]:a[s.top()]>a[i]))
s.pop();
if(s.empty())
{r[i]=-1;
s.push(i);
}
else
{r[i]=s.top();
s.push(i);
}
}
}
void nextSmallerOfNextGreater(int arr[],int n)
{int ng[n];
int rs[n];
next(arr,n,ng,'g');
next(arr,n,rs,'s');
for(int i=0;i<n;i++)
{if(ng[i]!=-1&&rs[ng[i]]!=-1)
{
cout<<arr[rs[ng[i]]]<<" ";
}
else
{
cout<<"-1  ";
}
cout<<"\n";
}
}
int main()
{int arr[] = {5, 1, 9, 2, 5, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextSmallerOfNextGreater(arr, n);
    return 0;
}
