#include<bits/stdc++.h>
using namespace std;
void printMedians(double* arr,int n)
{
	priority_queue<double>p;
	priority_queue<double,vector<double>,greater<double> >p1;
	double median=0;
	for(int i=0;i<n;i++)
	{
		if(p.size()>p1.size())
		      {
		    	if(arr[i]<median)
		    	{
		    	double a=p.top();
		    	p.pop();
		    	p1.push(a);
		    		p.push(arr[i]);
				}
				else
				p1.push(arr[i]);
				median=(p.top()+p1.top())/2.0;
			}
			else if(p.size()<p1.size())
			{   
			
				if(arr[i]>median)
				{	double a=p1.top();
				p1.pop();
				p.push(a);
				p1.push(arr[i]);
		       	}
				else
				p.push(arr[i]);
				median=(p.top()+p1.top())/2.0;


			}
			else
			{
				if(arr[i]<median)
				{
				 p.push(arr[i]);
				 median=p.top();
			    }
			    else
			    {
			    	p1.push(arr[i]);
			    	median=p1.top();
				}
			}
			cout<<median<<'\n';
	}
}
int main() 
{ 
    // stream of integers 
    double arr[] = {9384,887}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printMedians(arr, n); 
    return 0; 
} 
