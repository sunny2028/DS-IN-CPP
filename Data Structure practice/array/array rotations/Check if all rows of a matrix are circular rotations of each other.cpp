#include<bits/stdc++.h>//https://www.geeksforgeeks.org/check-rows-matrix-circular-rotations/
using namespace std;
bool checker(int mat[4][4])
{string s="";
for(int i=0;i<4;i++)
s=s+to_string(mat[0][i]);
string str=s+s;
for(int i=1;i<4;i++)
{string str1="";
for(int j=0;j<4;j++)
   str1=str1+to_string(mat[i][j]);
   if(str.find(str1)==string::npos)
   return false;
}
return true;
}

int main()
{int mat[4][4]={{1,2,3,4},{4,1,2,3},{3,4,1,2},{2,3,4,1}};
if(checker(mat))
cout<<"yes";
else
cout<<"no";
}
