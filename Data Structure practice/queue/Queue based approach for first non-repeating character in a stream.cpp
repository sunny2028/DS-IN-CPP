#include<bits/stdc++.h>
using namespace std;
void firstnonrepeating(char *str)
{
	queue<char>q;
	int arr[26]={0};
	for(int i=0;str[i];i++)
	{ 
		
		q.push(str[i]);
		
		arr[str[i]-'a']++;
		while(!q.empty())
		{ 
			if(arr[q.front()-'a']>1)
			{
				q.pop();
				if(q.empty())
				  cout<<"-1 ";
			}
			else
			{
				cout<<q.front()<<" ";
				break;
			}
		}
		
	}
	return ;
}

int main()
{
	char str[] = "otzomeqlftxz";
    firstnonrepeating(str);
    return 0;
}
