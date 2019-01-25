#include<bits/stdc++.h>
using namespace std;
stack<int> sortStack(stack<int>&s)
{
	stack<int> temp;
	while(!s.empty())
	{int a=s.top();
	s.pop();
	if(temp.empty()||a<temp.top())
       temp.push(a);
       else
       {
       	while(!temp.empty()&&a>temp.top())
       	{
       	s.push(temp.top());
		   temp.pop();	
		}
		temp.push(a);
	   }
	}
	return temp;
}
int main()
{
	stack<int> input;
    input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);
 
    // This is the temporary stack
    stack<int> tmpStack = sortStack(input);
    cout << "Sorted numbers are:\n";
 
    while (!input.empty())
    {
        cout << input.top()<< " ";
        input.pop();
    }
}
