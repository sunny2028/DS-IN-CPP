#include<bits/stdc++.h>
using namespace std;
int rotater(string str)
{string temp;
temp=str+str;
int n=str.length();
for(int i=1;i<=n;i++)
{ string substring=temp.substr(i,str.size());
      if(str==substring)
      return i;
}
}



int main()
{string str="aaaa";
cout<<rotater(str);
}
