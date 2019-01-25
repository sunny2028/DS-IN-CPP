#include<bits/stdc++.h>
using namespace std;
void printLeast(string s)
{int min_avail=1,posofi=0;
vector<int>v;
 if(s[0]=='I')
  {v.push_back(1);
  v.push_back(2);
  min_avail=3;
  posofi=1;
  }	
  else
  {
  	v.push_back(2);
  v.push_back(1);
  min_avail=3;
  posofi=0;
  }
  for(int i=1;i<s.length();i++)
  {
  	if(s[i]=='I')
  	{
  	v.push_back(min_avail);
	  min_avail++;
	  posofi=i+1;	
    }
    else
    {
    	v.push_back(v[i]);
    	for(int j=posofi;j<=i;j++)
    	v[j]++;
    	min_avail++;
	}
  }
  for(int i=0;i<v.size();i++)
  {
  	cout<<v[i];
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
