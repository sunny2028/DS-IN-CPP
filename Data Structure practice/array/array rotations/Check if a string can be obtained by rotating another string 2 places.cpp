#include<bits/stdc++.h>
using namespace std;
void check(string s1,string s3)
{string s2=s3;
int l;
reverse(s2.begin(),s2.begin()+2);
reverse(s2.begin()+2,s2.end());
reverse(s2.begin(),s2.end());
if(s1==s2)
cout<<"yes";
else
{l=s3.length();
reverse(s3.begin(),s3.begin()+l-2);
reverse(s3.begin()+l-2,s3.end());
reverse(s3.begin(),s3.end());
if(s1==s3)
cout<<"yes";
else
cout<<"no";
}
}
int main()
{string s1,s2;
cin>>s1>>s2;
check(s1,s2);

}
