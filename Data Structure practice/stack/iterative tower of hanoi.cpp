#include<bits/stdc++.h>
using namespace std;
void result(int n,char s,char d)
{
	cout<<"Move disc "<<n<<" from "<<s<<" to "<<d<<"\n";
}
void move(stack<int>&src,stack<int>&dept,char s,char d)
{

	if(src.empty())
	{
		src.push(dept.top());
		result(dept.top(),d,s);
			dept.pop();
	}
	else if(dept.empty())
	{	
		dept.push(src.top());
		result(src.top(),s,d);
		src.pop();
	}
	else if(src.top()>dept.top())
	{
		src.push(dept.top());
			result(dept.top(),d,s);
			dept.pop();
		
	}
		else 
	{ 
		dept.push(src.top());
			result(src.top(),s,d);
			src.pop();
	}
}
void movedisk(stack<int>&sr,stack<int>&aux,stack<int>&dest,int n)
{ 
	char s='S',d='D',a='A';
	if(n%2==0)
	{
	swap(d,a);
	}
	int totaliteration=pow(2,n)-1;
	for(int i=n;i>=1;i--)
	{
		sr.push(i);
	}

	for(int j=1;j<=totaliteration;j++)
	{
		if(j%3==1)
		  move(sr,dest,s,d);
		 else if(j%3==2)
		  move(sr,aux,s,a);
		 else if(j%3==0)
		  move(dest,aux,d,a);
			
	}
	
}
int main()
{
	stack<int>sr;
	stack<int>au;
	stack<int>dest;
	int n=2;
	movedisk(sr,au,dest,n);
	
}
