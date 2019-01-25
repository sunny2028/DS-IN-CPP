#include<bits/stdc++.h>
using namespace std;
void leftrotate(string &s,int d)
{reverse(s.begin(),s.begin()+d);
reverse(s.begin()+d,s.end());
reverse(s.begin(),s.end());
}
void rightrotate(string &s,int d)
{leftrotate(s,s.length()-d);
}
int main()
{string s="geeksforgeeks";
leftrotate(s,2);
cout<<s<<"\n";
string si="geeksforgeeks";
rightrotate(si,2);
cout<<si;
}
