#include<bits/stdc++.h>
using namespace std;
int minindex(queue<int>q,int size)
{ int min=INT_MAX;
     int res;
	for(int i=0;i<q.size();i++)
	{
		int curr=q.front();
		q.pop();
		if(curr<min&&i<size)
		     {
		     	min=curr;
		     	res=i;
			 }
			 q.push(curr);
	}
  cout<<res<<"\n";
	return res;
}
void insertMinToRear(queue<int> &q, int min_index)
{
    int min_val;
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        int curr = q.front();
        q.pop();
        if (i != min_index)
            q.push(curr);
        else
            min_val = curr;
    }
    q.push(min_val);
}
 
void print(queue<int>q)
{    int n=q.size();
		for(int i=0;i<n;i++)
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<"\n";
}
void sortqueue(queue<int>&q)
{int n=q.size();
	for(int i=0;i<n;i++)
	{
		int index=minindex(q,q.size()-i);
		insertMinToRear(q,index);
	}
}
int main()
{
	queue<int>q;
	q.push(23);
	q.push(4);
	q.push(14);
	q.push(34);
	q.push(2);
	sortqueue(q);
	print(q);

}
