#include<bits/stdc++.h>
using namespace std;           //time complexity:O(n)
void checkdivisibleby4(string s)
{int l,count=0,onedigit;
l=s.length();
if(l==1)
{if((s.at(0)-'0')%4==0)
     count++;

}
if(l==2)
{onedigit=(s.at(0)-'0')*10+s.at(1)-'0';
if(onedigit%4==0);
count++;
onedigit=(s.at(1)-'0')*10+s.at(0)-'0';
if(onedigit%4==0);
  count++;
}
if(l>=3)
{
for(int i=0;i<l-1;i++)
 {onedigit=(s.at(i)-'0')*10+s.at(i+1)-'0';
 if(onedigit%4==0)
    count++;
 }
 onedigit=(s.at(l-1)-'0')*10+s.at(0)-'0';
  if(onedigit%4==0)
    count++;
}
cout<<count;
}
int main()
{string s;
cin>>s;
checkdivisibleby4(s);

}
