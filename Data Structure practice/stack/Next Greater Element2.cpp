#include<iostream>
#include<stack>
using namespace std;
void nextgreaterelement(int *arr,int n,int *sp)
{
	stack<int>s;
	s.push(0);
	for(int i=1;i<n;i++)
	{
		while(!s.empty()&&arr[i]>arr[s.top()])
		{ sp[s.top()]=arr[i];
			s.pop();
		}
		//sp[i]=s.empty()?i+1:i-s.top();
		s.push(i);
		
	}
	while(!s.empty())
{
	sp[s.top()]=-1;
	s.pop();
}
	
}
int main()
{
	int arr[]={100, 80, 60, 70, 60, 75, 85};
	int arr1[7];
	nextgreaterelement(arr,7,arr1);
	for(int i=0;i<7;i++)
	{
		cout<<arr1[i]<<" ";
	}
	return 0;
}
