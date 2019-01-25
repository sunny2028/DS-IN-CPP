#include<bits/stdc++.h>
using namespace std;
string generate(string s)
{
	stack<int>global;
	stack<string>st;
	for(int i=0;i<s.length();i++)
	{int count=0;
		if(s[i]>='1'&&s[i]<='9')
		{while (s[i] >= '0' && s[i] <= '9')
            {
                count = count * 10 + s[i] - '0';
                i++;
            }
 
            i--;
            global.push(count);
	
	    }
		else if(s[i]==']')
		{   string a="";
			while(st.top()!="[")
			{  	
				a=st.top()+a;
				st.pop();
				
			}
		
			st.pop();
			int tp=global.top();
			global.pop();
			for(int j=0;j<tp;j++)
			{
				st.push(a);
			}
		}
		else
		{
		string h(1,s[i]);
		st.push(h);
	    }
		
	}
   string r="";
   while(!st.empty())
   {
 r=st.top()+r;
 st.pop();  	
   }
   return r;
}
int main()
{
	string s="3[b2[ca]]";
	cout<<generate(s);
}
