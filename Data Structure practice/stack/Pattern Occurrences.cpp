#include<bits/stdc++.h>
using namespace std;
int countpattern(string pattern,string text)
{ string s="";
int count=0;
	for(int i=0;i<text.length();i++)
	{
	s=s+text[i];
 int found=s.find(pattern);
 if(found!=string::npos)
 {
 count++;	
string t=s.substr(0,s.length()-pattern.length());
s=t;
 }

	}
	return count;
}
int main()
{
	string pattern="ABC";
	string text="ABABCABCC";
	cout<<countpattern(pattern,text);
}
