#include<bits/stdc++.h>
using namespace std;
string lexo(string m)
{string temp=m+m;
string n=m;
int k;
for(int i=0;i<m.length();i++)
{string str=temp.substr(i,m.size());
if(str<n)
{n=str;
k=i;
}
}
cout<<k<<"\n";
return(n);


}
int main()
{string m="nyta";
cout<<lexo(m);



}
