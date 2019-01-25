#include<bits/stdc++.h>
using namespace std;//https://www.geeksforgeeks.org/lexicographically-minimum-string-rotation/
string lexo(string n)//time complexity:O(n2Logn) under the assumption that we have used a O(nLogn) sorting algorithm.
{int len=n.length();
string temp=n+n;
string arr[len];
for(int i=0;i<len;i++)
{
arr[i]=temp.substr(i,len);
}
sort(arr,arr+len);
return(arr[0]);
}
int main()
{string m="nyta";
cout<<lexo(m);




}
