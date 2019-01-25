#include<bits/stdc++.h>
using namespace std;
void printLeast(string s)
{vector<int>v;
int minavail=0,posofI=0;
if(s[0]=='I')
{v.push_back(1);
v.push_back(2);
minavail=3;
posofI=1;
}
if(s[0]=='D')
{v.push_back(2);
v.push_back(1);
minavail=3;
posofI=0;
}
for(int i=1;i<s.length();i++)
{if(s[i]=='I')
{v.push_back(minavail);
minavail++;
posofI=i+1;
}
else
{v.push_back(v[i]);
for(int j=posofI;j<=i;j++)
{
v[j]++;
}
minavail++;
}
}
for(int i=0;i<v.size();i++)
{
cout<<v[i]<<" ";
}
cout<<"\n";
}
int main()
{

    printLeast("IDID");
    printLeast("I");
    printLeast("DD");
    printLeast("II");
    printLeast("DIDI");
    printLeast("IIDDD");
    printLeast("DDIDDIID");
    return 0;

}
