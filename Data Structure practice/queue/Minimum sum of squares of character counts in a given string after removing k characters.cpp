#include<bits/stdc++.h>
using namespace std;
int minStringValue(string str,int k)
{
	int count[26]={0};
	int sum=0;
	for(int i=0;str[i];i++)
	{
		count[str[i]-'a']++;
	}
	priority_queue<int>q;
	for(int i=0;i<26;i++)
	{
		q.push(count[i]);
	}
	while(k--)
	{
		int temp=q.top();
		q.pop();
		temp--;
		q.push(temp);
	}
	while(!q.empty())
	{ 
		sum=sum+q.top()*q.top();
		q.pop();
	}
	return sum;
}
int main()
{
	 string str = "abbccc";   // Input 1
    int k = 2;
    cout << minStringValue(str, k) << endl;
 
    str = "aaab";           // Input 2
    k = 2;
    cout << minStringValue(str, k);
 
    return 0;
}
