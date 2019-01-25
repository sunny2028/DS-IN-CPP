#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 5
struct ele
{
	int x;
	int y;
};
bool isvalid(int x,int y)
{
	return (x>=0&&y>=0&&x<R&&y<C);
}
bool isdelimator(ele temp)
{
	return (temp.x==-1&&temp.y==-1);
}
bool checkall(int arr[3][5])
{
		for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(arr[i][j]==1)
			return false;
		}
	
	}
	return true;
}
int counttimes(int arr[3][5])
{
	queue<ele>q;
	int count=0;
	ele temp;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(arr[i][j]==2)
			{
				temp.x=i;
				temp.y=j;
				q.push(temp);
			}
		}
	}
	temp.x=-1;
	temp.y=-1;
	q.push(temp);
while(!q.empty())	
{
	bool flag=false;
	while(!isdelimator(q.front()))
         {
         	temp=q.front();
         	if(isvalid(temp.x+1,temp.y)&&arr[temp.x+1][temp.y]==1)
         	     {
         	     if(!flag)
				  count++;
				  flag=true;
				  arr[temp.x+1][temp.y]=2;
				  temp.x++;
				  q.push(temp);
				  temp.x--;	
				 }
		    if(isvalid(temp.x-1,temp.y)&&arr[temp.x-1][temp.y]==1)
		    {
		    	    if(!flag)
				  count++;
				  flag=true;
				  arr[temp.x-1][temp.y]=2;
				  temp.x--;
				  q.push(temp);
				 temp.x++;
			}
			  if(isvalid(temp.x,temp.y+1)&&arr[temp.x][temp.y+1]==1)
		    {
		    	    if(!flag)
				  count++;
				  flag=true;
				  arr[temp.x][temp.y+1]=2;
				  temp.y++;
				  q.push(temp);
				  temp.y--;
			}
			  if(isvalid(temp.x,temp.y--)&&arr[temp.x][temp.y-1]==1)
		    {+
		    	    if(!flag)			  flag=true;
				  arr[temp.x][temp.y-1]=2;]
				  temp.y--;
				  q.push(temp);
				  temp.y++;
			}
			q.pop();
		 }	
		 q.pop();
		 if(!q.empty())
		 {
		 	temp.x=-1;
		 	temp.y=-1;
		 	q.push(temp); 
		 }
		 
}
return checkall(arr)?count:-1;
	
}
int main()
{
	int arr[R][C]={ {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}
		               };
		               
		cout<<counttimes(arr);               
}

