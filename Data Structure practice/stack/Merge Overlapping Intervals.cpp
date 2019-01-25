#include<bits/stdc++.h>
using namespace std;\
struct interval
{
	int start;
	int end;
};
bool compare(interval a,interval b)
{
	return a.start<b.start;
}
void mergeinterval(interval arr[],int n)
{
	sort(arr,arr+n,compare);
	stack<interval>s;
	s.push(arr[0]);
	for(int i=1;i<n;i++)
	{
		if(arr[i].start>s.top().end)
			s.push(arr[i]);
		
	   else if(arr[i].end>s.top().end)
		{
			s.top().end=arr[i].end;
		}
		
	}
	while(!s.empty())
	{
		cout<<"{"<<s.top().start<<" "<<s.top().end<<"}\n";
		s.pop();
	}
	
}
int main()
{interval abc[]={{1,3},{2,4},{5,6}};
mergeinterval(abc,3);
	
}
