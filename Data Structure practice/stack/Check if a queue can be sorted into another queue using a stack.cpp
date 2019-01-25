#include<bits/stdc++.h>
using namespace std;
bool checkSorted(int n,queue<int>q)
{
	stack<int>st;
	int expected=1;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		if(t==expected)
           expected++;
        else
        {
        	if(st.empty())
        	st.push(t);
        	else if(st.top()<t)
        	return false;
        	else
        	{
        		st.push(t);
			}
		}
		while(!st.empty()&&st.top()==expected)
		{
			st.pop();
			expected++;
		}	
	}
	return true;
}
int main()
{
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(6);
    q.push(3);
    q.push(4);
 
    int n = q.size();
 
    (checkSorted(n, q) ? (cout << "Yes") :
                         (cout << "No"));
 
    return 0;
}
