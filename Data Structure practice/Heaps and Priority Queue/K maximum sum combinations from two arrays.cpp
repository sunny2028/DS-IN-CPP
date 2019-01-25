#include<bits/stdc++.h>
using namespace std;
void KMaxCombinations(int A[], int B[], int N, int K)
{
	priority_queue<int>p1;
	priority_queue<int>p2;
	for(int i=0;i<N;i++)
	{
		p1.push(A[i]);
		p2.push(B[i]);
	}
	while(K--)
	{
		int a=p1.top();
		p1.pop();
		int b=p2.top();
		p2.pop();
		cout<<a+b<<"\n";
		if(a+p2.top()>b+p1.top())
		{
			p1.push(a);
		}
		else
		p2.push(b);
	}
 } 
 int main()
 {
 	int A[] = { 4, 2, 5, 1 }; 
    int B[] = { 8, 0, 5, 3 }; 
    int N = sizeof(A)/sizeof(A[0]); 
    int K = 3; 
    KMaxCombinations(A, B, N, K); 
    return 0; 
 }
