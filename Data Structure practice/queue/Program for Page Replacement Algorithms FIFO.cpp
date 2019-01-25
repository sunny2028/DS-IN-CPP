#include<bits/stdc++.h>
using namespace std;
int pageFaults(int arr[],int n,int size)
{
	queue<int>q;
	set<int>s;
	int fault=0,hit=0;
	for(int i=0;i<n;i++)
	{
		if(s.find(arr[i])==s.end())
		{
			if(q.size()<size)
			{     
				q.push(arr[i]);
				s.insert(arr[i]);
			}
			
			else
			{   int x=q.front();
				q.pop();
				q.push(arr[i]);
				s.erase(x);
				s.insert(arr[i]);

			}
			fault++;
		}
		else
		hit++;
	}
	cout<<hit<<"\n";
	return fault;
}
int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4,
                   2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;
    cout << pageFaults(pages, n, capacity);
    return 0;
}
