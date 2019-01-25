#include<bits/stdc++.h>
using namespace std;
struct abc
{int start;
int end;
};
bool compare(abc a,abc b)
{
return a.start<b.start;
}
void mergelap(abc arr[],int n)
{stack<abc>s;
sort(arr,arr+n,compare);
if(s.empty())
s.push(arr[0]);
for(int i=1;i<n;i++)
{abc top=s.top();
if(arr[i].start>top.end)
{
s.push(arr[i]);
}
else
{
if(top.end<arr[i].end)
{top.end=arr[i].end;
s.pop();
s.push(top);
}
}
}
cout << "\n The Merged Intervals are: ";
    while (!s.empty())
    {
        abc t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }
}
int main()
{abc arr[]={ {6,8}, {1,9}, {2,4}, {4,7} };
mergelap(arr,4);
}
