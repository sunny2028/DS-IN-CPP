#include <bits/stdc++.h>
using namespace std;
int countt(string s)
{
    stack<char>st;
    if(s.length()%2)
    return -1;
    int count=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='{')
        st.push(s[i]);
        else
        {
            if(st.empty())
            count++;
            else
            st.pop();
        }
    }
   return (count+st.size())/2+st.size()%2;
 }

int main() {
	int t;
	cin>>t;
	int i=1;
    while(i<=t)
    {
        string s;
        cin>>s;
        cout<<countt(s)<<"\n";
        i++;
    }
}
