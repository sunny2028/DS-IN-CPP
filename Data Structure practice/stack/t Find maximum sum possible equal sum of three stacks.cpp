#include<bits/stdc++.h>//https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/
using namespace std;
int maxSum(int stack[],int stack1[],int stack2[],int n,int n1,int n2)
{int sum=accumulate(stack,stack+n,0);
int sum1=accumulate(stack1,stack1+n1,0);
int sum2=accumulate(stack2,stack2+n2,0);
int top=0,top1=0,top2=0;
while(1)
{if(sum==sum1&&sum==sum2)
{
break;
}
if(top==n||top1==n1||top2==n2)
return -1;
if(sum>sum1&&sum>sum2)
sum=sum-stack[top++];
if(sum1>sum&&sum1>sum2)
sum1=sum1-stack1[top1++];
if(sum2>sum&&sum2>sum1)
sum2=sum2-stack2[top2++];
}
return sum;
}
int main()
{int stack1[] = { 3, 2, 1, 1, 1 };
  int stack2[] = { 4, 3, 2 };
  int stack3[] = { 1, 1, 4, 1 };

  int n1 = sizeof(stack1)/sizeof(stack1[0]);
  int n2 = sizeof(stack2)/sizeof(stack2[0]);
  int n3 = sizeof(stack3)/sizeof(stack3[0]);

  cout << maxSum(stack1, stack2, stack3, n1, n2, n3) << endl;
  return 0;
}
