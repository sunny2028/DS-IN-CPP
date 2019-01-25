#include<bits/stdc++.h>
using namespace std;
bool check(int arr[],int n,int m,int min)
{int curr_sum=0;
int students=1; ;
	for(int i=0;i<n;i++)
	{ if(arr[i]>min)
	        return false;
		if(curr_sum+arr[i]>min)
		{
			students++;
			curr_sum=arr[i];
			if(students>m)
			return false;
		}
		else
		curr_sum+=arr[i];
	}
	return true;
	
}
int findPages(int arr[],int n,int m)
{int sum=0;
	for(int i=0;i<n;i++)
	sum+=arr[i];
	int start=0,end=sum,mid,result=INT_MAX;
	while(start<=end)
	{
		 mid=(start+end)/2;
		 
		 if(check(arr,n,m,mid))
		 {
		 	result=min(mid,result);
		 	end=mid-1;
		 }
		 else
		 start=mid+1;
	}
	return result;
}
int main()
{//Number of pages in books
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof arr / sizeof arr[0];
    int m=3; //No. of students
 
    cout << "Minimum number of pages = "
         << findPages(arr, n, m) << endl;
    return 0;
}
