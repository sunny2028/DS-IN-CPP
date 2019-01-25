#include<bits/stdc++.h>
using namespace std;
int mod(string s,int N)
{
	int res=0;
	for(int i=0;s[i];i++)
	{
		res=res*10+s[i]-'0';
		res%=N;
	}
	return res;
}
string getMinimumMultipleOfBinaryDigit(int N)
{
	queue<string>q;
	q.push("1");
	set<int>st;
	while(!q.empty())
	{
		string s=q.front();
		q.pop();
		int rem=mod(s,N);
		  if(rem==0)
	         return s;
	         if(st.find(rem)==st.end())
	         {
	         	  q.push(s+"0");
	         	  q.push(s+"1");
	         	  st.insert(rem);
			 }
			  	
	}
}
int main() 
{ 
    int N = 12; 
    cout << getMinimumMultipleOfBinaryDigit(N); 
    return 0; 
} 
