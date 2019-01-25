#include<bits/stdc++.h>
using namespace std;
int count(vector<string>v)
{stack<string>s;
for(int i=0;i<v.size();i++)
{if(s.empty())
s.push(v[i]);
else
{
if(s.top().compare(v[i])==0)
s.pop();
else
s.push(v[i]);
}
}
return s.size();
}
int main()
{vector<string> v;
v.push_back("tom");
v.push_back("jerry");
v.push_back("jerry");
v.push_back("tom");
cout<<count(v);


}
