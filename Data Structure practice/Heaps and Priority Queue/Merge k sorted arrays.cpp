#include<bits/stdc++.h>
using namespace std;
struct person
{
	int arr;
	int nextindex;
	int value;
};
struct check
{
	bool operator()(person &p1,person &p2)
	{
		return p1.value>=p2.value;
	}
};
#define n 4
vector<int> mergeksortedarray( vector<vector<int> > arr)
{
	priority_queue<person,vector<person>,check>p;
		person obj;
	for(int i=0;i<arr.size();i++)
	{
		obj.arr=i;
		obj.nextindex=1;
		obj.value=arr[i][0];
		p.push(obj);
	}
	vector<int>arr1;
	int index=0;

	while(!p.empty())
	{
	 obj=p.top();
	arr1.push_back(obj.value);
	int a=obj.arr;
	int j=obj.nextindex;
	p.pop();
	if(j<arr[a].size())
	{
	
		obj.arr=a;
		obj.nextindex=j+1;
		obj.value=arr[a][j];
		p.push(obj);
	}
    }
    return arr1;
    
}
void printArray(vector<int>a)
{
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
}
int  main()
{
  vector<vector<int> >arr; 
int a[]= { 2, 6, 12 };
int b[]={ 1, 9 };
int c[]={ 23, 34, 90, 2000 };
vector<int>a1(a,a+3);
vector<int>a2(b,b+2);
vector<int>a3(c,c+4);
arr.push_back(a1);
arr.push_back(a2);
arr.push_back(a3);
    vector<int>output = mergeksortedarray(arr); 
  
    cout << "Merged array is " << endl; 
    printArray(output); 
  
    return 0; 
}
